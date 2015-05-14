import random
f = open("milktemp.in","w")
n = 1000
x = random.randint(0,1000)
y = random.randint(0,1000)
z = random.randint(0,1000)
f.write('%d %d %d %d\n'%(n,x,y,z))
for i in range(n):
	s = random.randint(0,1000000000)
	e = random.randint(s,1000000000)
	f.write("%d %d\n"%(s,e))