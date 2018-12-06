import timeit
start = timeit.default_timer()
file = open("input.txt","r")

chars = file.readline()

def removeAt(i, s):
    return s[:i] + s[i+1:]

def getpolymer(p):
    poly = p
    count = 0
    removedAll = False
    while not removedAll:
        count = count + 1
        removedAll = True
        for i,val in enumerate(poly):
            if i+1 < len(poly) and ( (ord(poly[i+1]) - ord(val) == -32) or (ord(poly[i+1]) - ord(val) == 32)):
                poly = removeAt(i+1,poly)
                poly = removeAt(i, poly)
                removedAll = False
                #print('count:', count)
                break
    return poly

def getSubPolyList(p):
    polies = set()
    count = 1
    poly = p
    #get all the characters
    chars = set()
    for i,val in enumerate(p):
        chars.add(val.lower())
    #remove the chars
    for i in chars:
        print('loop:', count)
        poly = p
        poly = p.replace(i,"")
        poly = poly.replace(i.upper(),"")
        poly = getpolymer(poly)
        polies.add(poly)
        count = count + 1
    return polies


ans2 = getSubPolyList(chars)
print('answer1:',len(getpolymer(chars)))
print('answer2:',len(sorted(ans2,key=len)[0]))
end = timeit.default_timer()
print('time:',end-start)