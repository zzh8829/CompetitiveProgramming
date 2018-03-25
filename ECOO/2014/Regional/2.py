def isColoured(mult,i,j):
	if i//mult%2==j//mult%2:
		return True
	return False
def colour(i,j):
	col = False
	for each in mults:
		if isColoured(each,i,j):
			col = (col==False)
	return col

data = open("DATA21.txt")
input = data.readline

for j in range(10):
	n = int(input())
	mults = []

	for i in range(1,int(n**0.5)+1):
		if n%i==0:
			mults.append(i)
			mults.append(n/i)
	mults.append(n)
	mults = list(set(mults))

	for i in range(5):
		a,b = list(map(int,input().strip().split(" ")))
		col = colour(a-1,b-1)
		if col:
			print("B",end="")
		else:
			print("G",end="")
	print("")
