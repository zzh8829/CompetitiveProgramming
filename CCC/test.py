s = set()
n = 40

def rec(cur,lis,ma):
	if cur==0:
		s.add(tuple(lis))
		return	
	for i in range(1,min(cur,ma)+1):
		rec(cur-i,lis[:]+[i],i)

rec(n,[],n)

a = list(s)
a.sort()

for i in a:
	print(i)
print(len(s))