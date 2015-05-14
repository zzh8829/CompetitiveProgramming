import sys
sys.stdout = open("shuffle.in","w")

import random

N = 100000 # 100,000
M = 50000 # 100,000
Q = N

print(N,M,Q)

a = [i+1 for i in range(M)]
random.shuffle(a)
for i in range(M):
	print(a[i])

for i in range(Q):
	print(i+1)