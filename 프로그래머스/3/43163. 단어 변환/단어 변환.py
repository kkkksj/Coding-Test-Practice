from collections import deque

def BFS(words, begin, target):
    q = deque()
    q.append((begin, 0))
    visited = [False]*len(words)
    
    result = 0
    while q:
        now, dist = q.popleft()
        if now == target:
            return dist
        for i in range(len(words)):
            if not visited[i]:
                word = words[i]
                cnt = 0
                for idx in range(len(word)):
                    if word[idx] != now[idx]:
                        cnt += 1
                if cnt == 1:
                    q.append((word, dist+1))
                    visited[i] = True
    return 0 

def solution(begin, target, words):
    answer = 0
    answer = BFS(words, begin, target)
    return answer