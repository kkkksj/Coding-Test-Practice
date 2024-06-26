def IsPrime(num):
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return 0
    return 1

import sys
m, n = map(int, sys.stdin.readline().split())
if m < 2:
    m = 2

for num in range(m, n+1):
    if IsPrime(num):
        print(num)