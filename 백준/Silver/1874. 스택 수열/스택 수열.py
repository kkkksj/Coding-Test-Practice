from collections import deque
import sys

n = int(sys.stdin.readline())

answer_list = deque()
for i in range(n):
    number = int(sys.stdin.readline())
    answer_list.append(number)

push_pop = []
stack = deque()
num = 1
while 1:
    if stack or num <= n:
        if stack and stack[0] == answer_list[0]:
            stack.popleft()
            answer_list.popleft()
            push_pop.append("-")
        elif num <= n:
            stack.appendleft(num)
            push_pop.append("+")
            num += 1
        elif num > n:
            push_pop = ["NO"]
            break
    else:
        break

for push_or_pop in push_pop:
    print(push_or_pop)
