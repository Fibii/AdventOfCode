import unittest

#setup
check = unittest.TestCase()
file = open("input.txt","r")
chars = 'abcdefghijklmnopqrstuvwxyz'

words = []
for i in file.readlines():
    words.append(str(i).rstrip())
check.assertEqual(words[249],'auxwobzrvqvpsjfgklthnyioqe')

#Part One
twice = 0
thrice = 0
demo1 = ['abcdef','bababc','abbcde','abcccd','aabcdd','abcdee','ababab']
for word in words:
    foundThree = False
    foundTwo = False
    for c in chars:
        if word.count(c) == 3 and not foundThree:
            thrice = thrice + 1
            foundThree = True

        elif word.count(c) == 2 and not foundTwo:
            twice = twice + 1
            foundTwo = True

checksum = thrice * twice
#check.assertEqual(checksum,12)
print(checksum)

#Part Two
demo2 = ['abcde','fghij','klmno','pqrst','fguij','axcye','wvxyz']
boxes = set({})
for word1 in words:

    for word2 in words[1:]:
        difference = 0
        sharedChar = ''
        if len(word1) != len(word2):
            break
        for i in range(len(word1)):
            if word1[i] != word2[i]:
                difference = difference + 1
                sharedChar = word1[i]
        #print("word1:",word1,"word2:",word2,"difference:",difference)
        if difference == 1:
            boxes.add(word1.replace(sharedChar,'')) #there is a bug here, had to manually remove the char

print(boxes)
