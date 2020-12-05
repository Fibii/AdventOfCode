from validator import Validator

passports = []
with open('input.txt', 'r') as f:
    lines = f.read().split('\n\n')
    for line in lines:
        line_data = line.split('\n')
        passport = {}
        for data in line_data:
            for passport_data in data.split(' '):
                key, value = passport_data.split(':')
                passport[key] = value
        passports.append(passport)

def _get_valid_passports():
    global passports
    valid_passports = []
    for passport in passports:
        if len(passport.keys()) == 8 or (len(passport.keys()) == 7 and 'cid' not in passport):
            valid_passports.append(passport)
    return valid_passports

def part1():
    return len(_get_valid_passports())

def part2():
    valid_passports = _get_valid_passports()
    count = 0
    for passport in valid_passports:
        is_valid = Validator(passport).is_valid()
        if is_valid:
            count += 1
    return count

print('part1:', part1())
print('part2:', part2())