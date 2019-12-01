from collections import Counter

file = open("solutiondata.txt","r")
dates = []
for i in file.readlines():
    dates.append(i.split(" ")[1].replace("[","").replace("]","").replace("'","").rstrip())

for k in dates:
    print(k)

counter = Counter(dates)
print(counter.most_common())