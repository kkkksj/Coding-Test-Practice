import sys
input = sys.stdin.readline

num = int(input())
num_list = list(map(int, input().split()))

dp = [0] * num
dp[0] = num_list[0]

for i in range(1, num):
    dp[i] = max(num_list[i], dp[i-1]+num_list[i])

print(max(dp))