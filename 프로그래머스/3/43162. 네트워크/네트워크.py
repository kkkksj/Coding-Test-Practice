from collections import deque

def BFS(n, computers, visited, start):
    visited[start] = True
    q = deque()
    q.append(start)
    
    while q:
        now = q.popleft()
        
        for i in range(n):
            if visited[i] or computers[now][i]==0:
                continue
            
            visited[i] = True
            q.append(i)
    
def solution(n, computers):
    answer = 0
    
    visited = [False] * n
    for i in range(n):
        if visited[i] == False:
            BFS(n, computers, visited, i)
            answer += 1;
    
    return answer