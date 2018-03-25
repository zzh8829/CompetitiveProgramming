#Problem        : Birthday Cake
#Language       : Python 3
#Compiled Using : py_compile
#Version        : Python 3.4.3
#Input for your program will be provided from STDIN
#Print out all output from your program to STDOUT

import sys

data = sys.stdin.read().splitlines()

n = int(data[0])

a = list(map(int, data[1:]))

maxn = 0
dp = a[:]

for i in range(1, n):
  for j in range(i):
    if a[i] >= a[j] and dp[i] < dp[j] + a[i]:
        dp[i] = dp[j] + a[i]

for i in range(n):
  if maxn < dp[i]:
    maxn = dp[i]

print(maxn)
