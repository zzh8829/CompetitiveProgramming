#Problem        : Numerical Palindromes
#Language       : Python 3
#Compiled Using : py_compile
#Version        : Python 3.4.3
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys

data = sys.stdin.read().splitlines()

line = data[0]


import collections

digits = list(line)
dc = collections.Counter(digits)

ds = list(reversed(sorted(list(set(digits)))))


maxs = -1
pal = ""
for d in ds:
  if dc[d] // 2 > 0:
    pal += str(d) * (dc[d] // 2)

  if dc[d] % 2 == 1 and maxs == -1:
    maxs = d

if maxs != -1:
  print(pal + str(maxs) +  "".join(reversed(pal)))
else:
  print(pal +  "".join(reversed(pal)))




