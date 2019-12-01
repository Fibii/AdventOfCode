from day3.fabric import Fabric
from day3.diagram import Diagram

#setup
file = open("input.txt","r")
input = []
for f in file.readlines():
    input.append(f)
file.close()

#list of fabrics
fabrics = []
tmp = ['#1 @ 1,3: 4x4','#2 @ 3,1: 4x4','#3 @ 5,5: 2x2']

#parse the data
for i in input:
    x = i.split(" ")
    id = int( x[0].replace("#", "") )
    leftEdge = int( x[2].split(",")[0] )
    topEdge = int( x[2].split(",")[1].replace(":","") )
    width = int( x[3].split("x")[0] )
    height = int( x[3].split("x")[1].rstrip() )
    f = Fabric(id,leftEdge,topEdge,width,height)
    fabrics.append(f)

d = Diagram(1000 ,1000)

for f in fabrics:
    d.fillGrid(f)
    print("added fabric:",f.getId())

ans = d.getRes()
print('answer1:',ans)

#Part Two
file = open("answer.txt","r")
lines = set(file.readlines()).pop()

for i in range(1,1323 +1,1):
    if str(i) not in lines:
        print('answer2:',i)