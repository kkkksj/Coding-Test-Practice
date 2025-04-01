# 이진탐색
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

trees = list(map(int, input().split()))

s, e = 1, max(trees)

while s <= e:
    h = (s+e)//2
    meter = 0
    for tree in trees:
        if tree > h:
            meter += (tree-h)
    if meter >= m:
        s = h + 1
    else:
        e = h - 1
print(e)