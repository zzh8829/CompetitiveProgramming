from heapq import*
inF = open("milktemp.in")
numCows,lowEff,goodEff,highEff = list(map(int,inF.readline().split(" ")))

lowhighs = []
for i in range(numCows):
    l,h = list(map(int,inF.readline().split(" ")))
    heappush(lowhighs,(l,"low"))
    heappush(lowhighs,(h,"high"))
bestSol = 0    
bestMilk = numCows*lowEff
while len(lowhighs)>0:
    x = heappop(lowhighs)
    if x[1] == "low":
        bestMilk += goodEff-lowEff
    if x[1] == "high":
        bestMilk -= goodEff-highEff
    bestSol = max(bestSol,bestMilk)
outF = open("milktemp.out","w")
outF.write(str(bestSol))
outF.close()


