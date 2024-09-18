import sys
from collections import defaultdict

t = int(input())

for i in range(t):
    n = int(sys.stdin.readline())

    dic = defaultdict(int)

    for j in range(n):
        name, type = sys.stdin.readline().split()
        dic[type] += 1

    answer = 1
    for k in dic.keys():
        answer *= (dic[k] + 1)

    print(answer - 1)