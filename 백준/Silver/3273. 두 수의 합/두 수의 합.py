from collections import deque

n = int(input())
num_list = list(map(int, input().split()))
num_list.sort()
x = int(input())

answer = 0
start = 0
end = n-1

while start != end:
    if num_list[start] + num_list[end] < x:
        start += 1
    elif num_list[start] + num_list[end] > x:
        end -= 1
    else:
        answer += 1
        start += 1

print(answer)