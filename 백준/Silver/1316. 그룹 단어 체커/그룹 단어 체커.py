def IsGroupWord(word):
    char = []
    for i in range(len(word)):
        if word[i] not in char:
            char.append(word[i])
        else:
            if word[i] != word[i-1]:
                return 0
    return 1

import sys
n = int(input())
num_group_word = 0

for i in range(n):
    word = sys.stdin.readline().rstrip()
    if IsGroupWord(word):
        num_group_word += 1
print(num_group_word)
