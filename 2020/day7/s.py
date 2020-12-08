bags = {}

def _clean(s):
    return s.replace('bags', '').replace('bag', '').replace('.', '').replace('\n', '').lstrip().rstrip()

with open('input.txt', 'r') as f:
    for line in f.readlines():
        _line = line.split(', ')
        _first_subline = _line[0].split(' contain ')
        name = _clean(_first_subline[0])
        if _first_subline[1][0] == 'n':
            continue
        else:
            contained_bag_size = int(_first_subline[1][0])
        contained_bag_name = _clean(_first_subline[1][2:])
        bags[name] = [(contained_bag_name, contained_bag_size)]
        for l in _line[1:]:
            contained_bag_size = int(l[0]) 
            contained_bag_name = _clean(l[2:])
            bags[name] += [(contained_bag_name, contained_bag_size)]


our_bag = 'shiny gold'

def part1():
    global our_bag, bags
    bag_queue = [our_bag]
    result = set()
    while bag_queue:
        bag_q = bag_queue.pop()
        for bag in bags.keys():
            values = [b[0] for b in bags[bag]]
            if bag_q in values:
                bag_queue.append(bag)
                result.add(bag)
    return len(result)

def part2():
    global our_bag, bags
    def solve(_bag=our_bag):
        if _bag not in bags:
            return 0
        root = bags[_bag]
        res = []
        for bag in root:
            res += [bag[1] * solve(bag[0]) + bag[1]]
        return sum(res)
    return solve()

print('part1:', part1())
print('part2:', part2())