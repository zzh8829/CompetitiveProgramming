import random

def genb(d):
  if d == 0:
    return ""
  t = random.randint(0,10)
  if t == 0:
    return ""
  if t < 4:
    return genb(d-1) + genb(d-1)
  
  return "(" + genb(d-1) + ")"

def flip(s2):
  s = list(s2)
  f1 = random.randint(0, len(s)-1)
  f2 = random.randint(0, len(s)-1)

  f1,f2 = min(f1,f2), max(f1,f2)
  
  for i in range(f1, f2+1):
    if s[i] == '(':
      s[i] = ')'
    else:
      s[i] = '('

  print(f1,f2)

  return "".join(s)

s = genb(5)
s = flip(s)

f = open("t1.txt", "w")
f.write(s)
f.close()
