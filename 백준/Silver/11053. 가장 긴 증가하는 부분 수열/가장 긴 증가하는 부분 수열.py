n = int(input())
A_i = list(map(int, input().split()))

dp = [1]*n
for i in range(1, n):
    for j in range(i):
        if A_i[j] < A_i[i]:
            dp[i] = max(dp[j]+1, dp[i])

print(max(dp))
