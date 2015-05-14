import random
f = open("crowded.in","w")
n = 50000
d = random.randint(0,1000000000)
f.write("%d %d\n"%(n,d))
for i in range(n):
	f.write("%d %d\n"%(random.randint(0,1000000000),random.randint(0,1000000000)))
