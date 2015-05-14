n = int(input())
for i in range(n):
	x = input()
	lx = hx = int(x)
	for j in range(len(x)):
		for k in range(j+1,len(x)):
			xx = list(x)
			xx[j],xx[k] = xx[k],xx[j]
			if xx[0] == '0':
				continue
			xx = int("".join(xx))
			lx = min(lx,xx)
			hx = max(hx,xx)
	print("Case #%d: %d %d"%(i+1,lx,hx))
