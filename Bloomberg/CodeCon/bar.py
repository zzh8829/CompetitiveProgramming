#Problem        : Birthday Cake
#Language       : Python 3
#Compiled Using : py_compile
#Version        : Python 3.4.3
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys

data = sys.stdin.read().splitlines()

n = int(data[0])

a = data[1:]

st = set()
vt = []

for i in a:
  name, s, e = i.split('|')
  s = int(s)
  e = int(e)

  vt.append((s,'b'))
  vt.append((e,'e'))

vt.sort()

tv = 0
mtv = 0

if vt[0][1] == 'b':
  tv = 1
  mtv = 1

for i in range(1, len(vt)):
  v = vt[i]
  if v[1] == 'b':
    tv += 1
  if v[1] == 'e':
    tv -= 1
  if v[0] != vt[i-1][0]:
    mtv = max(tv, mtv)

print(mtv)



