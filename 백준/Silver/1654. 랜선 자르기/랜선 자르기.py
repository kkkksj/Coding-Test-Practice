import sys
input = sys.stdin.readline

k, n = map(int, input().split())

cable = [0] * k
for i in range(k):
    cable[i] = int(input())

num_cable = 0
s, e = 1, max(cable)
while s <= e:
    num_cable = 0
    mid = (s+e) // 2
    for c in cable:
        num_cable += (c//mid)
    if num_cable < n:
        e = mid-1
    else:
        s = mid+1

print(e)