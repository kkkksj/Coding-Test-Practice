import sys
n = int(input())
schedule = [[0 for i in range(2)] for j in range(n+1)]

for i in range(1, n+1):
    t, p = map(int, sys.stdin.readline().split())
    schedule[i] = [t, p]

dp = [0] * (n+2)
for i in range(1, n+1):
    for j in range(i + schedule[i][0], n + 2): #상담일 + 걸리는 시간부터 쭉
        if dp[j] < dp[i] + schedule[i][1]: #현재 이익이 상담을 해서 이익이 증가되는 것보다 작으면 (== 일을 더 해야 이득임)
            dp[j] = dp[i] + schedule[i][1] #j번째 이익을 증가시킴
        #일을 안 하는 경우가 더 이득일 수 있음
print(dp[-1])