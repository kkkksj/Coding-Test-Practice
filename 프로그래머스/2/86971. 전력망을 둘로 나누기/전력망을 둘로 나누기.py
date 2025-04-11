from collections import deque
from collections import defaultdict

def BFS(node, cant_go, graph, n):
    visited = [False]*(n+1)
    visited[node] = True
    visited[cant_go] = True
    q = deque()
    q.append(node)
    result = 0
    
    while q:
        start = q.popleft()
        for node in graph[start]:
            if not visited[node]:
                visited[node] = True
                q.append(node)
                result += 1
    return result        
    
def solution(n, wires):
    answer = -1
    graph = defaultdict(list)
    min_del = 100
    
    for x, y in wires:
        graph[x].append(y)
        graph[y].append(x)
    
    for root1, root2 in wires:
        if root1 != root2:
            depth1 = BFS(root1, root2, graph, n)
            depth2 = BFS(root2, root1, graph, n)
            min_del = min(min_del, abs(depth1 - depth2))
    answer = min_del
    return answer