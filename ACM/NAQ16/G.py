sa = input()
la = len(sa)
a = int(sa)

import math

num = 0

i = 0

while True:
  i += 1

  num += math.log10(i)

  if(math.ceil(num) >= la- 100):
    print(i, num, la)

  if(math.ceil(num) == la):
    print(i)

  if(math.ceil(num) > la):
    break
