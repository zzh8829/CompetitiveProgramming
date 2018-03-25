#Problem        : 2016 Qualifiers - Uncle's Super Birthday Party
#Language       : Python 3
#Compiled Using : py_compile
#Version        : Python 3.4.3
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys

data = sys.stdin.read().splitlines()

n = int(data[0])

segs = []

for i in range(n-1):
  x,y = data[i+1].split()
  x2,y2 = data[i+2].split()
  segs.append(int(x),int(y), int(x2),int(y2))

