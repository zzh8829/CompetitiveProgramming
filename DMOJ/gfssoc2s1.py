s,m,l = list(map(int,input().split()))
x,y,z = list(map(float,input().split()))
t = 0

b = s//3
s -= b*3
t += x*b
bl = min(l,b)
l -= b
b -= bl
bm = min(m,b)
m -= bm
b -= bm

b2 = (s+m)//3
m = (s+m)-b2*3
t += s * x + (b2*3-s)*y
bl = min(l,b2)
l -= bl
b2 -= bl
