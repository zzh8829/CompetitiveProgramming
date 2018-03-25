import random
import sys
sys.stdout = open("C.in","w")
n = 10
k1 = random.randint(0,10)
k2 = n-k1
l1 = [i for i in range(1,11)]
random.shuffle(l1)
print(n)
print(k1, end=" ")
for i in range(k1):
	print(l1[i], end=" ")
print()
print(k2, end=" ")
for i in range(k2):
	print(l1[i+k1], end=" ")
print()
