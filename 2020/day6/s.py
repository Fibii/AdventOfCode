lines = []
with open('input.txt', 'r') as f:
    for line in f.read().split('\n\n'):
        lines += [line]

def part1():
    return sum([len(set(line.replace('\n', ''))) for line in lines])

def _solve(group):
    if len(group) == 1: return len(group[0])
    sets = []
    for subgroup in group:
        sets.append(set(subgroup))
    if len(sets) == 1: return 0
    return len(sets[0].intersection(*sets[1:]))

def part2():
    return sum([_solve(line.split('\n')) for line in lines])

print('part1:', part1())
print('part2:', part2())