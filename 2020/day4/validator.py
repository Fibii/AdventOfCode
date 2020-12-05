import re 

class Validator(object):
    def __init__(self, passport):
        self.passport = passport
    
    def _is_valid_year(self, key, _min, _max):
        passport = self.passport
        year = passport[key]
        if not year.isnumeric() or len(year) != 4:
            return False
        year = int(year)
        return year >= _min and year <= _max

    def _is_valid_byr(self):
        return self._is_valid_year('byr', 1920, 2002)

    def _is_valid_iyr(self):
        return self._is_valid_year('iyr', 2010, 2020)
        
    def _is_valid_eyr(self):
        return self._is_valid_year('eyr', 2020, 2030)

    def _is_valid_hgt(self):
        passport = self.passport
        if 'cm' in passport['hgt']:
            hgt = int(passport['hgt'].split('cm')[0])
            if hgt >= 150 and hgt <= 193:
                return True
        elif 'in' in passport['hgt']:
            hgt = int(passport['hgt'].split('in')[0])
            if hgt >= 59 and hgt <= 76:
                return True
        return False

    def _is_valid_hcl(self):
        passport = self.passport
        return bool(re.search(r'#[0-9a-f]{6}', passport['hcl']))

    def _is_valid_ecl(self):
        passport = self.passport
        colors = set(['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'])
        return passport['ecl'] in colors

    def _is_valid_pid(self):
        passport = self.passport
        pid = passport['pid']
        return len(pid) == 9 and pid.isalnum()

    def is_valid(self):
        return self._is_valid_byr() and self._is_valid_ecl()  \
        and self._is_valid_eyr() and self._is_valid_hcl() \
        and self._is_valid_hgt() and self._is_valid_iyr() \
        and self._is_valid_pid()