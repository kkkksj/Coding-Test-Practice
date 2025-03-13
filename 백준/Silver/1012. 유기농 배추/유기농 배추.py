import sys
sys.setrecursionlimit(10 ** 6)

test_case = int(input())

def dfs(arr, i, j, m, n):
    if i < 0 or j < 0 or n <= i or m <= j:
        return arr, 0
    if arr[i][j] == 1:
        arr[i][j] = 0
        dfs(arr, i-1, j, m, n)
        dfs(arr, i+1, j, m, n)
        dfs(arr, i, j-1, m, n)
        dfs(arr, i, j+1, m, n)
        return arr, 1
    else:
        return arr, 0

for case in range(test_case):
    m, n, k = map(int, input().split())
    arr = [[0 for j in range(m)] for i in range(n)]
    for num in range(k):
        x, y = map(int, input().split())
        arr[y][x] = 1

    num_result = 0
    for i in range(n):
        for j in range(m):
            arr, result = dfs(arr, i, j, m, n)
            num_result += result
    print(num_result)
