import random
import sys
import time

gen = True
if gen:
	n = 30
	l = random.sample([i for i in range(n*3)],n*2)
	p = sorted([(l[i*2],l[i*2+1]) for i in range(n)])
	sys.stdout = open("in.txt","w")

	print(n)
	print("\n".join(["%d %d"%i for i in p]))

	sys.stdout.close()
else:
	f = open("in.txt","r")
	n = int(f.readline())
	p = []
	for i in range(n):
		p.append(list(map(int,f.readline().split())))

from pygame import *
s = display.set_mode((n*30+20,200))
for pp in p:
	draw.line(s,(255,255,255),(pp[0]*10+20,150),(pp[1]*10+20,50),1)
r = True
while r:
	for e in event.get():
		if e.type == QUIT:
			r = False
	display.update()
	time.wait(10)

