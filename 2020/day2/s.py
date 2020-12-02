import collections

password_lines = [] # list of tuples of (letter, min, max, password)
with open('input.txt', 'r') as f:
    for line in f.readlines():
        line_split = line.split(':')
        policy = line_split[0].split('-')
        policy_split = policy[1].split(' ')
        min_occurence = int(policy[0])
        max_occurence = int(policy_split[0])
        letter = policy_split[1]
        password = line.split(' ')[2].strip()
        password_lines.append((letter, min_occurence, max_occurence, password))

def part1():
    global password_lines
    count = 0
    for line in password_lines:
        letter, min_occurence, max_occurence, password = line
        letter_occurence = password.count(letter)
        if letter_occurence >= min_occurence and letter_occurence <= max_occurence:
            count += 1
    return count

def part2():
    global password_lines
    count = 0
    for line in password_lines:
        letter, min_occurence, max_occurence, password = line
        left = min_occurence - 1
        right = max_occurence - 1
        if (password[left] == letter and password[right] != letter) or (password[left] != letter and password[right] == letter):
            count += 1
    return count

print('part1:', part1())
print('part2:', part2())