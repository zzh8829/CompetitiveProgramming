
line = "" 
b = 0
def r():
    global b
    if line[b] == "(":
        b+=1
        p = r()
        b+=1
        e1 = r()
        b+=1
        e2 = r()
        b+=1
        return p*(e1+e2) + (1-p)*(e1-e2)
    k = b
    while(b < len(line) and line[b]!=" " and line[b]!=")"): b+=1
    v = float(line[k:b])
    return v

while(True):
    line = raw_input()
    if line == "()":
        break
    b = 0
    print("%.2f"%r())
