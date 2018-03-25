import re

def  firstRepeatedWord(s):
    s = s.replace('\t',' ').replace(',',' ').replace(';',' ').replace(':',' ')
    .replace('-',' ').replace('.',' ')
    lst = s.split(" ")
    ws = set()
    for w in lst:
        if w:
            if w in ws:
                return w
            ws.add(w)
