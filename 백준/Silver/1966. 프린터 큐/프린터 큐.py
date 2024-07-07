import sys
from collections import deque
t = int(input())

def Check(q, m):
    cnt = 0
    while(1):
        max_num = max(q) #현재 가장 높은 중요도 
        tmp = q.popleft()
        if tmp == max_num: #현재 뽑은게 가장 높은 중요도일 때
            if m == 0: #궁금한 인덱스가 뽑혔다면
                return cnt + 1 #리턴
            else: #가장 중요도가 높지만 궁금한 인덱스가 아니면
                cnt += 1 #카운트 업
                m -= 1 #하나가 없어져 인덱스가 줄어듦
        else: #현재 뽑은게 가장 높은 중요도가 아닐 때
            q.append(tmp) #다시 뒤에 넣음
            if m == 0: #가장 높은 중요도가 아닌데 궁금한 인덱스면
                m = len(q) - 1 #맨 뒤로 보냄
            else: #아무것도 아니면
                m -= 1 #어쨋든 앞에서 하나 뽑혀서 궁금한 인덱스 뒤로 가니까 궁금한 인덱스는 당겨짐

for i in range(t):
    n, m = map(int, sys.stdin.readline().split())
    important = list(map(int, sys.stdin.readline().split()))
    q = deque(important) #중요도로 큐를 만듦
    print(Check(q, m))