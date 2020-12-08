instructions = [] # (operation: value)
with open('input.txt', 'r') as f:
    [instructions.append((l[:3], int(l[4:]))) for l in f.readlines()]

def _toggle_operation(operation):
    if operation == 'jmp':
        return 'nop'
    else:
        return 'jmp'

def _run(toggle_line=-1):
    accumulator = 0
    visited = set()
    line = 0
    if toggle_line > -1:
        edited_instructions = [i for i in instructions]
        edited_instructions[toggle_line] = (_toggle_operation(instructions[toggle_line][0]), instructions[toggle_line][1])
        _instructions = edited_instructions
    else:
        _instructions = instructions
    operation, value = _instructions[0]
    while True:
        if line in visited:
            if toggle_line > -1:
                break
            else:
                return accumulator
        visited.add(line)
        if operation == 'acc':
            accumulator += value
            line += 1
        elif operation == 'nop':
            line += 1
        elif operation == 'jmp':
            line += value
        if line >= len(_instructions):
            return accumulator
        operation, value = _instructions[line]
    return None

def part1(toggle_line=-1):
    return _run()

def part2():
    operations = []
    for i, line in enumerate(instructions): 
        operation = line[0]
        if operation == 'jmp' or operation == 'nop':
            operations.append(i)

    for i in operations:
        acc = _run(toggle_line=i)
        if acc:
            return acc

print('part1:', part1())
print('part2:', part2())