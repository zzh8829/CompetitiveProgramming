import random
import sys
n = 2000
d = 20
sys.stdout = open("C.in","w")
print("%d %d"%(n,d))

for i in range(n):
	print "%d "%random.randint(1,10000),