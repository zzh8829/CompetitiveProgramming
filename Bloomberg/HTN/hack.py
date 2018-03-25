primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397]

for a in range(65,91):
  for b in range(65, 91):
    c = 228 - a - b
    if c < 65 or c > 90: continue

    for d in range(65,91):
      if d % 3 != 0: continue

      for e in range(65, 91):
        if e % 3 != 0: continue
        f = 219 - d - e
        if f < 65 or f > 90: continue

        for g in range(0, 243):
          h = e + 1

          i = 243 - g - h
          if i < 65 or i > 90: continue

          j = 288 - a - d - g
          if j < 65 or j > 90: continue

          k = 320 - b - e - h
          if k < 65 or k > 90: continue

          l = 229 - j - k
          if l < 65 or l > 90: continue

          if not ((b == e-1) or (k == h + 1)):
            continue

          if c in (b,e,h,k):
            continue

          if g != h and h != i and g!=i:
            continue

          if min((a,b,c,d,e,f,g,h,i,j,k,l)) not in (j,k,l):
            continue

          if min((a,b,c,d,e,f,g,h,i,j,k,l)) in (a,b,c,d,e,f,g,h,i):
            continue

          if max((a,b,c,d,e,f,g,h,i,j,k,l)) not in (j,k,l):
            continue

          if max((a,b,c,d,e,f,g,h,i,j,k,l)) in (a,b,c,d,e,f,g,h,i):
            continue

          if sum(((b in primes),(e in primes),
                  (h in primes),(k in primes))) < 2:
            continue

          if sum(map(lambda x: x in primes, (a,d,g,j, c,f,i,l))) <= 0:
            continue

          if len(set((a,d,g,j)).intersection((c,f,i,l))) <= 0:
            continue

          print("###")
          print(a,b,c)
          print(d,e,f)
          print(g,h,i)
          print(j,k,l)
          print("###")



72 83 73
69 78 72
82 79 82
65 80 84

'H', 'S', 'I','
 'E', 'N', 'H',
 'R', 'O', 'R',
  'A', 'P', 'T

  TRON   HI SHE RAP
