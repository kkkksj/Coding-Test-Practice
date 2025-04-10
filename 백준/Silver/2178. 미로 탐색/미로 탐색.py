from collections import deque

n, m = map(int, input().split())

maze = []
for i in range(n):
    maze.append(list(map(int, list(input()))))

i_list = [-1, 1, 0, 0]
j_list = [0, 0, -1, 1]
q = deque()
q.append((0, 0))
while q:
    row, col = q.popleft()
    for i, j in zip(i_list, j_list):
        next_row, next_col = row+i, col+j
        if 0<=next_row<n and 0<=next_col<m and maze[next_row][next_col] == 1:
            maze[next_row][next_col] = maze[row][col] + 1
            q.append((next_row, next_col))
print(maze[n-1][m-1])