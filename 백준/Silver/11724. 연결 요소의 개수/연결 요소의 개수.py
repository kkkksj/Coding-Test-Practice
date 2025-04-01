import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(visited, point, graph):
    visited[point] = True
    for node in graph[point]:
        if visited[node] is False:
            dfs(visited, node, graph)

n, m = map(int, input().split())

graph = [[] for i in range(n+1)]

for i in range(m):
    u, v = map(int, input().split())

    graph[u].append(v)
    graph[v].append(u)

visited = [False] * (n+1)
cnt = 0
for i in range(1, n+1):
    if visited[i] is False:
        dfs(visited, i, graph)
        cnt += 1
        
print(cnt)