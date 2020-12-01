numbers = []
with open('input.txt', 'r') as f:
    for line in f.readlines():
        numbers.append(int(line))

target_sum = 2020

def part1():
    global numbers, target_sum

    arr = [0] * target_sum

    for num in numbers:
        arr[num] += 1

    for num in numbers:
        if arr[target_sum - num] == 1:
            x = num
            y = target_sum - x
            return (x, y)

def part2():
    global numbers, target_sum
    arr = sorted(numbers)
    for i in range(len(arr) - 2):
        l, r = 0, len(arr) - 1
        while l < r:
            s = arr[l] + arr[r] + arr[i]
            if s == target_sum:
                return (arr[l], arr[r], arr[i])
            elif s < target_sum:
                l += 1
            elif s > target_sum:
                r -= 1

x, y = part1()
print('part1:', x * y)
x, y, z = part2()
print('part2:', x * y * z)
