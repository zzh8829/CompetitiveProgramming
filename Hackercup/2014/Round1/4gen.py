import sys
sys.stdout = open("4.txt","w")
import random
T = 20
N = 9

print(T)

for i in range(T):
	print(N,random.randint(1,20))
	for i in range(N):
		print(random.randint(0,50))

# 2
# 3 7 9 13
# 4 8 10 15
# 2 4 5 16