grid = []
with open('input.txt', 'r') as f:
    for line in f.readlines():
        grid.append(list(line.strip()))

def part1(i=1, j=3):
    n_rows = len(grid)
    n_cols = len(grid[0])
    count = 0
    y, x = i, j
    for _ in grid:
        if y >= n_rows:
            return count
        if grid[y][x] == '#':
            count += 1
        y, x = y + i, (x + j) % n_cols

def part2():
    slopes = [(1, 1), (3, 1), (5, 1), (7, 1), (1, 2)]
    result = 1
    for slope in slopes:
        result *= part1(slope[1], slope[0])
    return result

print('part1:', part1())
print('part2:', part2())