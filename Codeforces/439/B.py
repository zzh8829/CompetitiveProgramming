n,x = list(map(int,input().split()))
l = list(map(int,input().split()))
l.sort()
t = 0
for i in l:
	t += i * x
	x = max(1,x-1)
print(t)