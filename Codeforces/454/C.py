m = 4
n = 4

# + n*m

t = []
ts = []

'''
n = 2 
5 9  2
4 7  2
3 5  2 
2 3  2
1 1

n = 3
5 61    24       6
4 37    18       6
3 19    12       6
2 7     6        6
1 1 

n = 4
4 175          110     60    24
3 65           50      36   
2 15           14
1 1
'''

tot = 0

def rec(p,l):
	global tot
	if p==n:
		tot+= max(l)
		ts.append(max(l))
		return
	for i in range(m):
		l2 = l[:]
		l2.append(i+1)
		rec(p+1,l2)

rec(0,[])

print(tot)
print(tot/pow(m,n))

import collections
import pprint

ct = collections.Counter(ts)
pprint.pprint(ct)