
import java.util.*;

public class A
{
   public static void main(String[] args)
   {
      new A(new Scanner(System.in));
   }

   int N, M, maxRadius;
   circle2[] villages;
   vec2[] minions;

   // Try minion center as the center minion and spin a circle around that
   // point without restricting the radius. If no villages were present, this
   // would be the optimal solution.
   int spinMinions(int center)
   {
      Event[] events = new Event[2*N+2*(M-1)];
      int fptr = 0, bptr = 0;
      long diameter2 = maxRadius*4L*maxRadius;

      // Add all the minion events
      int activeMinions = 1; // Include ourselves in our count
      for (int i=0; i<M; i++) if (i != center)
      {
         long dd = minions[i].idist2(minions[center]);
         if (dd > diameter2) continue;
         vec2 dv = minions[i].sub(minions[center]);
         double d = Math.sqrt(dd);
         double a = Math.acos(d/(2.0*maxRadius));
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
         long a = maxRadius+(int)villages[i].rad;
         long b = maxRadius;
         long ab = a+b;
         long ab2 = ab*ab;
         long c2 = villages[i].cen.idist2(minions[center]);
         if (c2 > ab2) continue;

         vec2 dv = villages[i].cen.sub(minions[center]);
         double c = Math.sqrt(c2);
         double ang = Math.atan2(dv.y, dv.x);

         double top = b*b+c*c-a*a;
         double bot = 2*b*c;
         //System.out.printf("%.6f %.6f %.6f %.6f\n",top, bot, top/bot, Math.acos(top/bot));
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
      for(int i=0;i!=bptr;i++)
      {
         System.out.printf("%.6f %d ", events[i].p, events[i].t);
      }
      System.out.printf("\n");
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
      long diameter = maxRadius*2+(int)v1.rad+(int)v2.rad;
      long diameter2 = diameter*diameter;
      long distBetweenVillages = v1.cen.idist2(v2.cen);
      if (diameter2 <= distBetweenVillages) return 0;

      int nCandidates = 0;
      circle2[] candidateCircles = new circle2[2*M];
      for (int i=0; i<M; i++)
      {
         circle2 tmp = new circle2(minions[i], 0);

         vec2[] centers = v1.intersect(tmp, maxRadius, 1);
         if (centers == null) continue;
         if (centers.length == 1)
         {
            circle2 cand = new circle2(centers[0], maxRadius);
            boolean isOK = cand.touches(v2);
            for (int j=0; j<N; j++)
               if (cand.overlaps(villages[j]))
                  isOK = false;
            if (isOK) candidateCircles[nCandidates++] = cand;
            continue;
         }

         for (int t=0; t<2; t++)
         {
            circle2 cand = new circle2(centers[t], maxRadius);
            // If the circle is unrestricted, we don't care!
            if (!cand.overlapsOrTouches(v2)) continue;

            // Yay! we can start our binary search now!
            double lo = (v1.cen.dist(minions[i])-v1.rad)*0.5, hi = maxRadius;
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

   public A(Scanner in)
   {
      N = in.nextInt();
      M = in.nextInt();
      maxRadius = in.nextInt();

      villages = new circle2[N];
      for (int i=0; i<N; i++)
         villages[i] = new circle2(new vec2(in.nextInt(), in.nextInt()), in.nextInt());

      minions = new vec2[M];
      for (int i=0; i<M; i++)
         minions[i] = new vec2(in.nextInt(), in.nextInt());

      int res = 1; // We can make a circle of 0 radius to cover at least one minion.
      for (int i=0; i<M; i++)
         res = Math.max(res, spinMinions(i));
      //System.out.println(res);
      for (int i=0; i<N; i++)
         for (int j=i+1; j<N; j++)
            res = Math.max(res, sweepTwoVillages(i, j));

      System.out.println(res);
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
      double T = tri[0]+tri[1];
      if (GEOM.eq(T, tri[2])) return 1;
      return T>tri[2]?2:0;
   }
}