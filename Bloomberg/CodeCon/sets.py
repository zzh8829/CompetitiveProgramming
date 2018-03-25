#Problem        : Minimum Sets
#Language       : Python 3
#Compiled Using : py_compile
#Version        : Python 3.4.3
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys

data = sys.stdin.read().splitlines()

n = int(data[0])
a = data[1:]

op = set()
sets = {}
arr = []

for i in a:
  if i[0] == '^':
    op.add(i[1])

    if not i[1] in arr:
      arr.append(i[1])

    if not i[1] in sets:
      sets[i[1]] = []

  elif i[0] == '/':
    if i[1] in op:
      op.remove(i[1])

  else:
    num = int(i)
    #print(num, op)
    for k in op:
      sets[k].append(num)
    #print(sets)

for s in sorted(arr):
  st = ""
  if s in sets and len(sets[s]) > 0:
    st = " " + " ".join(map(lambda x: str(x), (sorted(sets[s]))))
  print("%c"%s + st)


