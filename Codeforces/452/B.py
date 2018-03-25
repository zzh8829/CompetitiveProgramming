from math import *

def d(p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y):
	if len(set([(p1x,p1y),(p2x,p2y),(p3x,p3y),(p4x,p4y)])) != 4:
		return (0,0)
	dis = sqrt((p2x-p1x)*(p2x-p1x) + (p2y-p1y)*(p2y-p1y)) + \
		sqrt((p3x-p2x)*(p3x-p2x) + (p3y-p2y)*(p3y-p2y)) + \
		sqrt((p4x-p3x)*(p4x-p3x) + (p4y-p3y)*(p4y-p3y))
	return (dis,(p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y))

def bf():
	l = []
	for p1x in range(0,n+1):
		for p1y in range(0,m+1):
			for p2x in range(0,n+1):
				for p2y in range(0,m+1):
					for p3x in range(0,n+1):
						for p3y in range(0,m+1):
							for p4x in range(0,n+1):
								for p4y in range(0,m+1):
									if len(set([(p1x,p1y),(p2x,p2y),(p3x,p3y),(p4x,p4y)])) == 4:
										l.append(d(p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y))

	print(list(reversed(sorted(l)))[0])

n,m = list(map(int,input().split()))

#bf()

if m==0:
	print("%d %d\n%d %d\n%d %d\n%d %d\n"%(1,0,n,m,0,0,n-1,m))
elif n==0:
	print("%d %d\n%d %d\n%d %d\n%d %d\n"%(0,1,n,m,0,0,n,m-1))
else:
	l = []
	l.append(d(n-1,m,0,0,n,m,0,1))
	l.append(d(n,m-1,0,0,n,m,1,0))
	l.append(d(1,0,n,m,0,0,n-1,m))
	l.append(d(0,1,n,m,0,0,n,m-1))
	l.append(d(0,0,n,m,0,1,n-1,m))
	l.append(d(0,0,n,m,1,0,n,m-1))
	l.append(d(0,0,n,m,n,0,0,m))
	l.append(d(0,0,n,m,0,m,n,0))
	
	a = list(reversed(sorted(l)))[0]
	#print(a)
	a = a[1]
	for i in range(4):
		print(a[i*2],a[i*2+1])

