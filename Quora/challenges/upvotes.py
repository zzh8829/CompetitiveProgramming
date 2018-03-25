import sys
import random
sys.stdout = open("upvotes.in","w")
n = 100
k = 20
print("%d %d"%(n,k))

for i in range(n):
	print(random.randint(1,1000))
