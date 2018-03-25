#Problem        : Birthday Cake
#Language       : Python 3
#Compiled Using : py_compile
#Version        : Python 3.4.3
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys

data = sys.stdin.read().splitlines()

n,m = data[0].split()
n = int(n)
m = int(m)

a = list(map(int, data[1].split()))

lst = []
for i in range(n):
  lst.append((a[i], i))

i = 0
t = 0
while True:

  Mov = False
  for j in range(i, n):
    if lst[j][0] > lst[i][0]:
      #print(j,i)
      lst.append(lst[i])
      lst.pop(i)
      Mov = True
      break

  #print(i,t, Mov, lst)

  if Mov:
    continue
  else:
    t += 1
    if lst[i][1] == m:
      break
    i += 1

print(t * 2)
