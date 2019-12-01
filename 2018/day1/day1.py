file = open("input.txt","r")
frequencies = []

#get the frequencies
for i in file.readlines():
    frequencies.append(int(i))

#Part One
res = sum(frequencies)
print("res:",res)

#Part Two
sum = 0
tmpResult = {0}
found = False
count = 0

while not found:
    for t in frequencies:
        sum = sum + t
        count = count + 1
        if sum in tmpResult:
            found = True
            print("repeated is:", sum)
            break
        else:
            tmpResult.add(sum)
print("current loop: ",count)