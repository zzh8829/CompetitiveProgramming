cc = int(input())
for ccc in range(cc):
	P,C,F = list(map(int,input().split()))
	n = int(input())
	l = []
	for i in range(n):
		l.append(list(map(int,input().split())))
	for i in range(2**n):
		p,c,f = 0,0,0
		e = str("%021d"%(int(bin(i)[2:])))[-n:]
		for j in range(n):
			if e[j] == '1':
				p += l[j][0]
				c += l[j][1]
				f += l[j][2]
		if (p,c,f) == (P,C,F):
			print("ok",j)

