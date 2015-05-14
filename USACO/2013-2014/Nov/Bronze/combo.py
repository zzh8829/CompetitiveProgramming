from heapq import*
inF = open("combo.in")
high = int(inF.readline())

johnC = list(map(int,inF.readline().split(" ")))
masterC = list(map(int,inF.readline().split(" ")))
ways = 250
dups = 1
d0 = max(5-abs(johnC[0]-masterC[0]),0)
d1 = max(5-abs(johnC[1]-masterC[1]),0)
d2 = max(5-abs(johnC[2]-masterC[2]),0)
dups = dups*d0*d1*d2
outF = open("combo.out","w")
outF.write(str(ways-dups))
outF.close()
