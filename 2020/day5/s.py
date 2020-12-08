lines = []
with open('input.txt', 'r') as f:
    lines = f.read().split('\n')

def _partition(line, left=0, right=127, d_l='F', d_r='B'):
    l, r = left, right
    for direction in line:
        m = l + (r - l) // 2
        if direction == d_l:
            r = m
        elif direction == d_r:
            l = m + 1
    return l

def _get_seat_ids():
    seats_ids = []
    for line in lines:
        row = _partition(line[:7])
        column = _partition(line[7:], 0, 7, 'L', 'R')
        seat_id = row * 8 + column
        seats_ids.append(seat_id)
    return seats_ids


def part1():
    return max(_get_seat_ids())

def part2():
    seats_ids = _get_seat_ids()
    for i in range(min(seats_ids), max(seats_ids)):
        if i not in seats_ids and (i - 1) in seats_ids and (i + 1) in seats_ids:
            return i


print('part1:', part1())
print('part2:', part2())