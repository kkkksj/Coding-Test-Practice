# 이진탐색
import sys
input = sys.stdin.readline

text = input()
text2list = list(text.split('-'))

for i in range(len(text2list)):
    num = text2list[i]
    if '+' in num:
        num_list = map(int, list(num.split('+')))
        text2list[i] = sum(num_list)
    else:
        text2list[i] = int(num)

result = text2list[0]
for num in text2list[1:]:
    result -= num

print(result)
