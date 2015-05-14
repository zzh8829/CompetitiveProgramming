inF = open("nocow.in")
lines, findK = list(map(int,inF.readline().split(" ")))
adjectives = []
used = []
for i in range(lines):
    line = inF.readline()
    adjs = line.split(" ")
    del adjs[:4]
    del adjs[-1]
    used.append(adjs)
    if i==0:
        adjectives = [[] for k in range(len(adjs))]
    for i in range(len(adjs)):
        adjectives[i].append(adjs[i])
for i in range(len(adjectives)):
    adjectives[i] = list(set(adjectives[i]))
    adjectives[i].sort()

product = 1
for i in adjectives:
    product*=len(i)
def count(depth):
    total = 0
    for each in used:
        for i in range(depth+1):
            match = True
            if (each[i] == adjectives[i][spots[i]])== False:
                match = False
                break
        if match:
            total += 1
    return total
def pTot(depth):
    total = 1
    for i in range(depth+1):
        total *= len(adjectives[i])
    return total
spots = [0]*len(adjectives)
depth = 0
while True:
    if product//pTot(depth)<findK:
        findK -= product//len(adjectives[depth])
        findK += count(depth)
        spots[depth] += 1
    else:
        depth += 1
        if depth == len(adjectives)-1:
            spots[depth] = findK-1
            break
outF = open("nocow.out","w")
for i in range(len(adjectives)):
    outF.write(adjectives[i][spots[i]])
    if i!=len(adjectives)-1:
        outF.write(" ")
outF.close()
        

