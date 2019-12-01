with open('day1.txt') as file : lines = file.readlines()
numbers = [int(line.strip()) for line in lines]
sum1 = sum2 = 0
for num in numbers:
    sum1 += num // 3 - 2
    n = num
    while n // 3 - 2 > 0:
        n = n // 3 - 2
        sum2 += n
print(sum1, sum2)