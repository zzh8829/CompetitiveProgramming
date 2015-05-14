import random

n = 20000
k = 100

f = open("E.in","w")
f.write("%d %d\n"%(n,k))
for i in range(n):
	f.write("%d "%random.randint(1,1000000))
f.write("\n")
f.close()