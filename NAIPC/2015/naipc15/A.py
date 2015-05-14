import pygame
from pygame.locals import *
import math
import sys
import os
import threading
import random
import time
import collections

# One boundary point known
def make_circle(points, p):
    c = (p[0], p[1], 0.0)
    for (i, q) in enumerate(points):
        if not _is_in_circle(c, q):
            if c[2] == 0.0:
                c = _make_diameter(p, q)
            else:
                c = _make_circle_two_points(points[0 : i + 1], p, q)
    return c


# Two boundary points known
def _make_circle_two_points(points, p, q):
    diameter = _make_diameter(p, q)
    if all(_is_in_circle(diameter, r) for r in points):
        return diameter

    left = None
    right = None
    for r in points:
        cross = _cross_product(p[0], p[1], q[0], q[1], r[0], r[1])
        c = _make_circumcircle(p, q, r)
        if c is None:
            continue
        elif cross > 0.0 and (left is None or _cross_product(p[0], p[1], q[0], q[1], c[0], c[1]) > _cross_product(p[0], p[1], q[0], q[1], left[0], left[1])):
            left = c
        elif cross < 0.0 and (right is None or _cross_product(p[0], p[1], q[0], q[1], c[0], c[1]) < _cross_product(p[0], p[1], q[0], q[1], right[0], right[1])):
            right = c
    return left if (right is None or (left is not None and left[2] <= right[2])) else right


def _make_circumcircle(p0, p1, p2):
    # Mathematical algorithm from Wikipedia: Circumscribed circle
    ax = p0[0]; ay = p0[1]
    bx = p1[0]; by = p1[1]
    cx = p2[0]; cy = p2[1]
    d = (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) * 2.0
    if d == 0.0:
        return None
    x = ((ax * ax + ay * ay) * (by - cy) + (bx * bx + by * by) * (cy - ay) + (cx * cx + cy * cy) * (ay - by)) / d
    y = ((ax * ax + ay * ay) * (cx - bx) + (bx * bx + by * by) * (ax - cx) + (cx * cx + cy * cy) * (bx - ax)) / d
    return (x, y, math.hypot(x - ax, y - ay))


def _make_diameter(p0, p1):
    return ((p0[0] + p1[0]) / 2.0, (p0[1] + p1[1]) / 2.0, math.hypot(p0[0] - p1[0], p0[1] - p1[1]) / 2.0)


_EPSILON = 1e-12

def _is_in_circle(c, p):
    return c is not None and math.hypot(p[0] - c[0], p[1] - c[1]) < c[2] + _EPSILON


# Returns twice the signed area of the triangle defined by (x0, y0), (x1, y1), (x2, y2)
def _cross_product(x0, y0, x1, y1, x2, y2):
    return (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0)

grunning = True

random.seed(2)
with open("A.in","w") as f:
	n = 5
	m = 100
	r = 250
	f.write("%d %d %d\n"%(n,m,r))
	for i in range(n):
		f.write("%d %d %d\n"%(random.randint(-960,960),
							  random.randint(-540,540),
							  random.randint(1,300)))
	for i in range(m):
		f.write("%d %d\n"%(random.randint(-960,960),
						 random.randint(-540,540)))


#sys.stdin = open("/Users/Zihao/Desktop/areaofeffect/data/in/areaofeffect.in11")
sys.stdin = open("A.in")

gN,gM,gR = list(map(int,input().split()))
gvillages = []
gminions = []
for i in range(gN):
	gvillages.append(list(map(int,input().split())))

for i in range(gM):
	gminions.append(list(map(int,input().split())))

gobjects = collections.OrderedDict()
gobjects_lock = threading.Lock()

def idist2(a,b):
	return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1])

def sub(a,b):
	return (a[0]-b[0],a[1]-b[1])

class Solver(threading.Thread):

	def __init__(self):
		super().__init__()

	def spinMinions(self, center):
		#print("gg")

		res = 0

		events = [0] * (2*gN+2*(gM-1))
		fptr = 0
		bptr = 0
		diameter2 = gR * 4 * gR

		activeMinions = 1; # Include ourselves in our count

		with gobjects_lock:
			gobjects['proc_m'] = {}
			gobjects['proc_n'] = {}

		#print("gm")

		for i in range(gM):
			if i != center:
				dd = idist2(gminions[i],gminions[center])
				if (dd > diameter2):
					continue
				dv = sub(gminions[i],gminions[center])
				d = math.sqrt(dd)
				a = math.acos(d/(2.0*gR))
				ang = math.atan2(dv[1], dv[0]);
				e1 = ang-a
				e2 = ang+a;
				#print("minion %.6f %.6f -- %.6f"%(e1, e2, ang));

				with gobjects_lock:
					gobjects['proc_m'][i] = (e1,e2,ang)

				if (e1 < -math.pi):
					activeMinions+=1;
					e1 += 2*math.pi;
				events[bptr] = (e1, 1, i); # Add minion
				bptr += 1
				if (e2 > math.pi):
					activeMinions+=1;
					e2 -= 2*math.pi;
				events[bptr] = (e2, 2, i); # Remove minion
				bptr += 1

		#print("gn")


		activeVillages = 0
		for i in range(gN):
			a = gR + gvillages[i][2];
			b = gR;
			ab = a+b;
			ab2 = ab*ab;
			c2 = idist2((gvillages[i][0],gvillages[i][1]),gminions[center])
			if (c2 > ab2):
				continue
			dv = sub((gvillages[i][0],gvillages[i][1]),gminions[center])
			c = math.sqrt(c2);
			ang = math.atan2(dv[1], dv[0])
			top = b*b+c*c-a*a;
			bot = 2*b*c;
			#print(a,b,c,top,bot,(gvillages[i][0],gvillages[i][1]),gminions[center])
			if not (-1 <= top/bot <= 1):
				return 1
			else:
				A = math.acos(top/bot);
				e1 = ang-A
				e2 = ang+A;

			with gobjects_lock:
				gobjects['proc_n'][i] = (e1,e2,ang)

			if (e1 < -math.pi):
				activeVillages+=1;
				e1 += 2*math.pi;
			events[bptr] = (e1, 3, i); # Add village
			bptr += 1
			if (e2 > math.pi):
				activeVillages+=1;
				e2 -= 2*math.pi;
			events[bptr] = (e2, 0, i); # Remove village
			bptr += 1

		#print('st')

		events = events[:bptr]
		events.sort(key = lambda x:(x[0],-(x[1])))

		if (activeVillages == 0):
			res = activeMinions;

		with gobjects_lock:
			gobjects['events'] = events

		def equals(x,y):
			if (abs(x[0]-y[0]) < 1e-6):
				if(x[1] == y[1]):
					return True
			return False

		with gobjects_lock:
			gobjects['active_n'] = [0] * gN
			gobjects['active_m'] = [0] * gM

		while (fptr < bptr):
			first = events[fptr];
			while (fptr < bptr and equals(first,events[fptr])):
				cur = events[fptr];
				fptr += 1
				with gobjects_lock:
					if (cur[1] == 1):
						activeMinions+=1;
						gobjects['active_m'][cur[2]] = 1
					elif (cur[1] == 2):
						activeMinions-=1;

						gobjects['active_m'][cur[2]] = 0
					elif (cur[1] == 3):
						activeVillages+=1;

						gobjects['active_n'][cur[2]] = 1
					elif (cur[1] == 0):
						activeVillages-=1;

						gobjects['active_n'][cur[2]] = 0
					else:
						print("BADNESS");
			#//System.out.println(activeMinions+" "+activeVillages);
			if (activeVillages == 0):
				with gobjects_lock:
					gobjects['active_2'] = gobjects['active_m'][:]
					gobjects['circle'] = make_circle([gminions[i] for i in range(gM) if gobjects['active_2'][i]==1],gminions[center])
				res = max(res, activeMinions);
				if not grunning:
					break
				time.sleep(0.03)
		return res

	def run(self):
		global gN,gM,gR,gvillages,gminions
		while True:
			with gobjects_lock:
				gobjects['map'] = (gvillages,gminions)

			res = 1
			for i in range(gM):

				#print('g1')
				with gobjects_lock:
					gobjects['center'] = i

				#print('g2')
				res = max(res, self.spinMinions(i))

				if not grunning:
					return
				time.sleep(0.1)

			random.seed(time.time())
			with open("A.in","w") as f:
				n = 5
				m = 100
				r = 250
				f.write("%d %d %d\n"%(n,m,r))
				for i in range(n):
					f.write("%d %d %d\n"%(random.randint(-960,960),
										  random.randint(-540,540),
										  random.randint(1,300)))
				for i in range(m):
					f.write("%d %d\n"%(random.randint(-960,960),
									 random.randint(-540,540)))


			#sys.stdin = open("/Users/Zihao/Desktop/areaofeffect/data/in/areaofeffect.in11")
			sys.stdin = open("A.in")

			gN,gM,gR = list(map(int,input().split()))
			gvillages = []
			gminions = []
			for i in range(gN):
				gvillages.append(list(map(int,input().split())))

			for i in range(gM):
				gminions.append(list(map(int,input().split())))

		'''
		for i in range(N):
			for j in range(i+1,N):
				res = max(res,sweepTwoVillages(i,j))
		'''

		print(res)

def xy(x,y):
	return (960+x, (540 - y))

def color(*v):
	return pygame.Color(*v)

pygame.init()
resolution = (width, height) = (1920, 1080)
screen = pygame.display.set_mode(resolution,pygame.FULLSCREEN)
clock = pygame.time.Clock()

pygame.font.init()
myfont = pygame.font.SysFont("Consolas", 11)

solver = Solver()
solver.start()
while grunning:
	clock.tick(60)
	screen.fill(0)
	for event in pygame.event.get():
		if event.type == QUIT:
			grunning = False
		elif event.type == pygame.KEYDOWN:
			if event.key == pygame.K_ESCAPE:
				grunning = False
			elif event.key == pygame.K_q:
				grunning = False

	pygame.draw.line(screen, color('gray'), xy(-960,0), xy(960,0), 1)
	pygame.draw.line(screen, color('gray'), xy(0,-540), xy(0,540), 1)

	with gobjects_lock:
		for typ,obj in gobjects.items():
			if typ == 'map':
				for village in obj[0]:
					pygame.draw.circle(screen, color('green'), xy(village[0],village[1]), village[2], 1)
				for minion in obj[1]:
					screen.set_at(xy(minion[0],minion[1]),color('red'))
			elif typ == 'proc_m!':
				for i,l in obj.items():
					label = myfont.render("%3f %3f %3f"%l, 1, color('white'))
					screen.blit(label, xy(gminions[i][0],gminions[i][1]))
			elif typ == 'proc_n!':
				for i,l in obj.items():
					label = myfont.render("%3f %3f %3f"%l, 1, color('purple'))
					screen.blit(label, xy(gvillages[i][0],gvillages[i][1]))
			elif typ == 'events':
				k=0
				s = 100
				sd = len(obj)/155
				for p,t,i in obj:
					label = myfont.render("%d"%k, 1, (0,s,s))
					if t == 1:
						screen.blit(label, xy(gminions[i][0],gminions[i][1]-10))
					if t == 2:
						screen.blit(label, xy(gminions[i][0],gminions[i][1]+20))
					if t == 3:
						screen.blit(label, xy(gminions[i][0],gminions[i][1]-10))
					if t == 0:
						screen.blit(label, xy(gminions[i][0],gminions[i][1]+20))
					k += 1
			elif typ == 'active_2':
				for i in range(gM):
					if obj[i] == 0:
						pygame.draw.circle(screen, color('orange'), xy(gminions[i][0],gminions[i][1]), 5, 0)
					if obj[i] == 1:
						pygame.draw.circle(screen, color('purple'), xy(gminions[i][0],gminions[i][1]), 5, 0)
			elif typ == 'active_n!':
				for i in range(gN):
					if obj[i] == 0:
						pygame.draw.circle(screen, color('orange'), xy(gvillages[i][0],gvillages[i][1]), 5, 0)
					if obj[i] == 1:
						pygame.draw.circle(screen, color('purple'), xy(gvillages[i][0],gvillages[i][1]), 5, 0)
			elif typ == 'circle':
				if(int(obj[2]) > 0):
					pygame.draw.circle(screen, color('yellow'), xy(int(obj[0]),int(obj[1])), int(obj[2]), 1)
		if 'center' in gobjects:
			obj = gobjects['center']
			pygame.draw.circle(screen, color('white'), xy(gminions[obj][0],gminions[obj][1]), 5, 0)

	pygame.display.flip()
sys.exit(0)


'''
	// Try minion center as the center minion and spin a circle around that
	// point without restricting the radius. If no villages were present, this
	// would be the optimal solution.
	int spinMinions(int center)
	{
	  Event[] events = new Event[2*N+2*(M-1)];
	  int fptr = 0, bptr = 0;
	  long diameter2 = gR*4L*gR;

	  // Add all the minion events
	  int activeMinions = 1; // Include ourselves in our count
	  for (int i=0; i<M; i++) if (i != center)
	  {
		 long dd = minions[i].idist2(minions[center]);
		 if (dd > diameter2) continue;
		 vec2 dv = minions[i].sub(minions[center]);
		 double d = Math.sqrt(dd);
		 double a = Math.acos(d/(2.0*gR));
		 double ang = Math.atan2(dv.y, dv.x);
		 double e1 = ang-a, e2 = ang+a;
		 //System.out.printf("minion %.6f %.6f -- %.6f%n", e1, e2, ang);
		 if (e1 < -Math.PI)
		 {
			activeMinions++;
			e1 += 2*Math.PI;
		 }
		 events[bptr++] = new Event(e1, 1); // Add minion

		 if (e2 > Math.PI)
		 {
			activeMinions++;
			e2 -= 2*Math.PI;
		 }
		 events[bptr++] = new Event(e2, 2); // Remove minion
	  }

	  // Add events for active circles that can block us using a circle.
	  int activeVillages = 0;
	  for (int i=0; i<N; i++)
	  {
		 long a = gR+(int)villages[i].rad;
		 long b = gR;
		 long ab = a+b;
		 long ab2 = ab*ab;
		 long c2 = villages[i].cen.idist2(minions[center]);
		 if (c2 > ab2) continue;

		 vec2 dv = villages[i].cen.sub(minions[center]);
		 double c = Math.sqrt(c2);
		 double ang = Math.atan2(dv.y, dv.x);

		 double top = b*b+c*c-a*a;
		 double bot = 2*b*c;
		 double A = Math.acos(top/bot);
		 double e1 = ang-A, e2 = ang+A;

		 //System.out.printf("village %.6f %.6f -- %.6f%n", e1, e2, ang);
		 if (e1 < -Math.PI)
		 {
			activeVillages++;
			e1 += 2*Math.PI;
		 }
		 events[bptr++] = new Event(e1, 3); // Add village

		 if (e2 > Math.PI)
		 {
			activeVillages++;
			e2 -= Math.PI;
		 }
		 events[bptr++] = new Event(e2, 0); // Remove village
	  }

	  // Run the sweep
	  Arrays.sort(events, fptr, bptr);
	  int res = 0;
	  if (activeVillages == 0)
		 res = activeMinions;
	  //System.out.println(activeMinions);
	  while (fptr < bptr)
	  {
		 Event first = events[fptr];
		 while (fptr < bptr && first.compareTo(events[fptr]) == 0)
		 {
			Event cur = events[fptr++];
			if (cur.t == 1)
				activeMinions++;
			else if (cur.t == 2)
				activeMinions--;
			else if (cur.t == 3)
				activeVillages++;
			else if (cur.t == 0)
				activeVillages--;
			else
				System.out.println("BADNESS");
		 }
		 //System.out.println(activeMinions+" "+activeVillages);
		 if (activeVillages == 0)
			res = Math.max(res, activeMinions);
	  }
	  //System.out.println(activeMinions+" "+res);
	  return res;
	}

	// The other case is to reduce the circle size, this is accomplished by
	// sweeping between two villages.
	int sweepTwoVillages(int village1, int village2)
	{
	  circle2 v1 = villages[village1], v2 = villages[village2];
	  long diameter = gR*2+(int)v1.rad+(int)v2.rad;
	  long diameter2 = diameter*diameter;
	  long distBetweenVillages = v1.cen.idist2(v2.cen);
	  if (diameter2 <= distBetweenVillages) return 0;

	  int nCandidates = 0;
	  circle2[] candidateCircles = new circle2[2*M];
	  for (int i=0; i<M; i++)
	  {
		 circle2 tmp = new circle2(minions[i], 0);

		 vec2[] centers = v1.intersect(tmp, gR, 1);
		 if (centers == null) continue;
		 if (centers.length == 1)
		 {
			circle2 cand = new circle2(centers[0], gR);
			boolean isOK = cand.touches(v2);
			for (int j=0; j<N; j++)
				if (cand.overlaps(villages[j]))
				  isOK = false;
			if (isOK) candidateCircles[nCandidates++] = cand;
			continue;
		 }

		 for (int t=0; t<2; t++)
		 {
			circle2 cand = new circle2(centers[t], gR);
			// If the circle is unrestricted, we don't care!
			if (!cand.overlapsOrTouches(v2)) continue;

			// Yay! we can start our binary search now!
			double lo = (v1.cen.dist(minions[i])-v1.rad)*0.5, hi = gR;
			//System.out.printf("%.6f %.6f%n", lo, hi);
			for (int iter=0; iter<200; iter++)
			{
				double m = (lo+hi)*0.5;
				vec2[] centers2 = v1.intersect(tmp, m, 2);
				cand = new circle2(centers2[t], m);
				if (cand.overlaps(v2))
				  hi = m;
				else
				  lo = m;
			}

			vec2[] centers2 = v1.intersect(tmp, lo, 2);
			cand = new circle2(centers2[t], lo);
			//System.out.println(cand);
			boolean isOK = true;
			for (int j=0; j<N; j++)
				if (cand.overlaps(villages[j]))
				  isOK = false;
			if (isOK) candidateCircles[nCandidates++] = cand;
		 }
	  }

	  int res = 0;
	  for (int i=0; i<nCandidates; i++)
	  {
		 circle2 cur = candidateCircles[i];

		 // Find out how many points are contained in this circle
		 int count = 0;
		 for (int j=0; j<M; j++)
			if (cur.contains(minions[j]))
				count++;
		 //System.out.println(cur+" "+count);
		 res = Math.max(res, count);
	  }

	  return res;
	}

}

class Event implements Comparable<Event>
{
	double p; // position in sweep (angle, or projected distance)
	int t; // type of event. Sweep dependant. This problem has many sweeps.

	public Event(double pp, int tt)
	{
	  p=pp;
	  t=tt;
	}

	public int compareTo(Event rhs)
	{
	  if (Math.abs(p-rhs.p) < 1e-9) return t-rhs.t;
	  return Double.compare(p, rhs.p);
	}
}

class circle2
{
	vec2 cen;
	double rad;

	public circle2(vec2 cc, double rr)
	{
	  cen=cc; rad=rr;
	}

	boolean contains(vec2 p)
	{
	  double d = cen.dist(p);
	  return GEOM.eq(d, rad) || d < rad;
	}

	boolean touches(circle2 rhs)
	{
	  double d = cen.dist(rhs.cen);
	  double rr = rad+rhs.rad;
	  return GEOM.eq(d, rr);
	}

	boolean overlaps(circle2 rhs)
	{
	  double d = cen.dist(rhs.cen);
	  double rr = rad+rhs.rad;
	  return !GEOM.eq(d, rr) && d < rr;
	}

	boolean overlapsOrTouches(circle2 rhs)
	{
	  double d = cen.dist(rhs.cen);
	  double rr = rad+rhs.rad;
	  return GEOM.eq(d, rr) || d < rr;
	}

	// Checks circle-circle intersection with an expanded radius.
	// Useful for finding a circle tangent to two circles.
	vec2[] intersect(circle2 rhs, double er, int type)
	{
	  double L = rad+er;
	  double R = rhs.rad+er;
	  double B = cen.dist(rhs.cen);

	  int nSols = GEOM.testTriangle(L, R, B);
	  if (nSols == 0) return null; // no solution

	  double c = (B*B+L*L-R*R)/(2*B);
	  double b = Math.sqrt(Math.max(L*L-c*c, 0));
	  vec2 u = rhs.cen.sub(cen).normalize();
	  vec2 v = new vec2(-u.y, u.x);
	  vec2 vc = u.scale(c), vb = v.scale(b);

	  if (type != 2 && nSols == 1) return new vec2[]{cen.add(vc).add(vb)};
	  return new vec2[]{cen.add(vc).add(vb), cen.add(vc).sub(vb)};
	}

	public String toString()
	{
	  return String.format("%s, %.6f%n", cen, rad);
	}
}

class vec2
{
	double x, y;

	public vec2(double xx, double yy)
	{
	  x=xx; y=yy;
	}

	vec2 add(vec2 rhs)
	{
	  return new vec2(x+rhs.x, y+rhs.y);
	}

	vec2 sub(vec2 rhs)
	{
	  return new vec2(x-rhs.x, y-rhs.y);
	}

	vec2 scale(double s)
	{
	  return new vec2(x*s, y*s);
	}

	vec2 normalize()
	{
	  double s = mag();
	  if (s < 1e-9) System.out.println("BADNESS NORMALIZE");
	  return scale(1.0/s);
	}

	// Only use on int coords
	long idist2(vec2 rhs)
	{
	  long dx = (int)x-(int)rhs.x;
	  long dy = (int)y-(int)rhs.y;
	  return dx*dx+dy*dy;
	}

	double dist(vec2 rhs)
	{
	  double dx = x-rhs.x;
	  double dy = y-rhs.y;
	  return Math.sqrt(dx*dx+dy*dy);
	}

	double mag()
	{
	  return Math.sqrt(x*x+y*y);
	}

	public String toString()
	{
	  return String.format("<%.6f, %.6f>", x, y);
	}
}

class GEOM
{
	static double EPS = 1e-9;
	static boolean eq(double a, double b)
	{
	  double d = Math.abs(a-b);
	  if (d < EPS) return true;
	  return d < EPS*Math.max(Math.abs(a), Math.abs(b));
	}

	static int testTriangle(double a, double b, double c)
	{
	  double[] tri = new double[]{a, b, c};
	  Arrays.sort(tri);
	  double T = tri[0] + tri[1];
	  if (GEOM.eq(T, tri[2])) return 1;
	  return T>tri[2]?2:0;
	}
}
'''
