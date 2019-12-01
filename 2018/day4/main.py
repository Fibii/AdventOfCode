from day4.dates import Dates
import datetime
import re
from day4.guard import Guard

dates = Dates().dates

guards = []


currentId = 0
addtime = False
for i,val in enumerate(dates):

    if (len( str(re.findall("[#]\S*", val)))  != 2):
        id = re.findall("[#]\S*", val)[0]
        currentId = id
        addtime = False
        #print("added guard:",id)
    else:
        id = currentId
        addtime = True
    #print('addtime:', addtime)
    if (len( str(re.findall("begins\s*", val) ))  > 2):
        begins = str(re.findall("begins\s*", val)[0]).rstrip().replace(" ","")
    else:
        begins = ''
    if (len( str(re.findall("falls\s*", val) ))  > 2) :
        falls = str(re.findall("falls\s*", val)[0]).rstrip().replace(" ","")
    else:
        falls = ''
    if (len( str(re.findall("wakes\s*", val) ))  > 3):
        wakes = str(re.findall("wakes\s*", val)[0]).rstrip().replace(" ","")
    else:
        wakes = ''

    date = dates[i].split("] ")[0].replace("[", "").replace(" ", "-").replace(":", "-")
        #print('added date:',date)

    if id == currentId and addtime:
        for guard in guards:
            if guard.id == currentId:
                guard.addTime(date,begins,falls,wakes)
                #print("#### added time to guard:",guard.id,"with date:",date,"wakes:",wakes,"falls:",falls,"begins:",begins)
    else:
        guards.append(Guard(id, begins, falls, wakes, date))
        #print('added guard:', id, 'with begins:', begins, 'falls:', falls, 'wakes:', wakes, 'date:', date)

s = [] #sleep unsorted
for i in guards:
    #s.append("0"+str(i.sleepTime) + "~id:" + str(i.id))
     if i.id == '#971':
         for j in i.dateList:
             print((str(j)))

s.sort()
for i in s :
    print(i)
#answer is: 07:29:00~id:#971


def mostTime(id):
    return id
