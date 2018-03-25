#Problem        : Expecto Palindronum
#Language       : Python 3
#Compiled Using : py_compile
#Version        : Python 3.4.3
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys

data = sys.stdin.read().splitlines()

s = data[0]
s2 = "".join(reversed(s))

l = len(s)
for i in range(len(s2)):
    f2 = s2[i:]
    f1 = s[:len(s) - i]
    print(f1,f2, i)
    if f1 == f2:
      l = i
      break

print(l)
