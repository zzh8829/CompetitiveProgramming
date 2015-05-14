a = [0]*5005
a[0] = 1
for i in range(5002):
   print(2.0*(2*i+1)/(i+2))
   a[i+1] = a[i]*2*(2*i+1)/(i+2)
f = lambda x:sum([a[i]*a[x-i] for i in range(x+1)])
print(f(input()))