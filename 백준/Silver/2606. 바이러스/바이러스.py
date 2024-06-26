import sys
from collections import deque

computer_num = int(input())
set_num = int(input())
num = {}
for i in range(set_num):
    a, b = map(int, sys.stdin.readline().split())

    if a in num: #a가 이미 있는 경우 추가
        num[a].append(b)
    else: #없는 경우 연결된 번호를 담을 덱 생성
        num[a] = deque([b])
    if b in num: #b가 이미 있는 경우 추가
        num[b].append(a)
    else: #없는 경우 연결된 번호를 담을 덱 생성
        num[b] = deque([a])


if 1 not in num: #번호 1이 아예 없는 경우
    print(0)
else:
    q = deque()
    node = 1 #노드 1번부터 시작
    cnt = 0
    while(1):
        if num[node]: #현재 노드의 연결된 덱이 비어 있지 않은 경우
            while(num[node]): #덱이 빌 때까지
                tmp = num[node].pop()
                if tmp not in q: #노드의 덱을 팝해서 q에 없을 때만 추가
                    q.appendleft(tmp)
                    cnt += 1 #q에 추가한다는 것은 1에 연결돼 있단 뜻으로 cnt를 올림
            node = q.pop() #현재 노드를 q에서 팝한 값으로 업데이트
        else: #현재 노드의 연결된 덱이 비어있는 경우 (연결된게 없음, 이미 방문함)
            cnt -= 1 #q에서 꺼낸값인데 이미 비어있다는 것은 방문했던 노드이므로 cnt를 증감시킴
            node = q.pop() #노드 업데이트

        if not q and not num[node]: #q도 비어있고 노드에 연결된 것도 없으면
            cnt -= 1 #방문한 노드이으모 cnt증감
            break
    print(cnt)