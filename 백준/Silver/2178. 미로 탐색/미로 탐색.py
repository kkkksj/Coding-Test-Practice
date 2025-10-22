import sys
from collections import deque
input = sys.stdin.readline

i_list = [0, 0, -1, 1]
j_list = [-1, 1, 0, 0]
def BFS():
    q = deque()
    visited = [[False for j in range(m)]for i in range(n)]
    q.append([0, 0, 1])
    visited[0][0] = True

    while len(q):
        now_i, now_j, cnt = q.popleft()
        if now_i == n-1 and now_j == m-1:
            return cnt

        for d in range(4):
            next_i = now_i + i_list[d]
            next_j = now_j + j_list[d]

            if next_i<0 or next_i>=n or next_j<0 or next_j>=m or visited[next_i][next_j] or grid[next_i][next_j]=='0':
                continue

            visited[next_i][next_j] = True
            q.append([next_i, next_j, cnt+1])

    return -1

n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(input())

print(BFS())