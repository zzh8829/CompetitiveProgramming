n = int(input())
s = input()
cnt = 0
keys = {chr(i):0 for i in range(ord('a'),ord('z')+1)}
for i in range(len(s)//2):
	keys[s[i*2]] += 1
	if keys[s[i*2+1].lower()] == 0:
		cnt += 1
	else:
		keys[s[i*2+1].lower()]-=1
print(cnt)