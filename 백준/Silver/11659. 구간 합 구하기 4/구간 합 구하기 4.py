import sys
n, m = map(int, input().split())
num = list(map(int, input().split()))
sum_num = [0] * (n+1) #누적합을 생성할 배열

for i in range(1, n+1):
    sum_num[i] = sum_num[i-1] + num[i-1] #누적합 생성

for i in range(m):
    i, j = map(int, sys.stdin.readline().split())
    print(sum_num[j] - sum_num[i-1]) #j번까지의 누적합에서 i-1까지의 누적합을 뺌