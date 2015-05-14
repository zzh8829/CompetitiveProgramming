
import sys
sys.setrecursionlimit(200005)
for shit in range(int(input())):
	n = int(input())
	fa = list(map(int,input().split()))
#	fa = [0]+[random.randint(1, i) for i in range(1,200000)]
	import collections

	so = [[] for i in range(200001)]

	for i in range(len(fa)):
		so[fa[i]].append(i+1)

	def fk(n):
		if len(so[n]) == 0:
			return (1,1)
		l = list(map(fk,so[n]))
		s = sorted(list(set(map(lambda k:k[0],l))))
		#print(l,s)
		for i in range(len(s)):
			if i+1 < s[i]:
				return (i+1,sum(map(lambda k:k[1],l)) + i+1)
		return (len(s)+1,sum(map(lambda k:k[1],l)) + len(s)+1)

	print(fk(1))
