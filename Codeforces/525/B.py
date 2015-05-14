s = list(input())
n = len(s)
m = int(input())
a = list(map(int,input().split()))
l = [0]*(n+1)
for i in a:
	l[i-1]+=1
	l[n-i+1]-=1
k = 0
l2 = []
for i in range(n):
	k += l[i]
	if k%2==0:
		l2.append(s[i])
	else:
		l2.append(s[n-i-1])
print("".join(l2))