n = int(input())

for i in range(n):
    dp = [[0 for j in range(2)] for k in range(41)]
    dp[0] = [1, 0]
    dp[1] = [0, 1]
    num = int(input())
    for j in range(2, num+1):
        dp[j][0] = dp[j-1][0] + dp[j-2][0]
        dp[j][1] = dp[j - 1][1] + dp[j - 2][1]

    print(dp[num][0], dp[num][1])