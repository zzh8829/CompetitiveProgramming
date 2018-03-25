import sys
sys.stdin = open("shuffle.in")
sys.stdout = open("shuffle.out","w")

N,M,Q = list(map(int,input().split()))

P = [0 for i in range(M)]
P2 = [0 for i in range(M)]
num = [i for i in range(N)]

for i in range(M):
	P[i] = int(input())-1
	P2[P[i]] = i

new = [0 for i in range(M)]
for c in range(N-M+1):
	for i in range(M):
		new[i] = num[P2[i]+c]
	num[c:c+M] = new

#print(num)

for i in range(Q):
	print(num[N-int(input())]+1)
