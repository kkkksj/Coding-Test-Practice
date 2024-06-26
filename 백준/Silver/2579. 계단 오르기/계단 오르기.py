"""
DP로 풀려고 먼저 계단 한 칸(dp[1], 두 칸(dp[2]), 세 칸(dp[3])을 오를 때를 생각함
dp[0] = 0
dp[1] = stair[1] #단순히 계단 한 칸을 오름
dp[2] = stair[1] + stair[2] #두칸을 오를 때 max는 첫번째와 두번째를 모두 밟는 것
dp[3] = max(stair[1]+stair[3], stair[2]+stair[3]) #세칸은 첫번째와 세번째를 밟거나 두번째와 세번째를 밟는 것 중 큰 것임
dp[3]에서 stair[1]은 dp[1]로 볼 수 있음 즉, dp[i-2]
          stair[2]+stair[3]은 앞에 stair[0] 즉,dp[0] == dp[i-3]이 생략된 걸로 볼 수 있음
이를 이용해 점화식을 만듦
"""
import sys

n = int(input())
stair = [0] * (n+1)
for i in range(1, n+1):
    stair[i] = int(sys.stdin.readline()) #앞에 출발칸을 하나 두고 추가

#위에서 설명한 초기화
dp = [0] * (n+1)
dp[1] = stair[1]
if n > 1: #계단이 2개 이상일 때만
    dp[2] = stair[1] + stair[2]

for i in range(3, n+1):
    #위에서 설명한 아이디어의 점화식
    dp[i] = max(dp[i-2] + stair[i], dp[i-3] + stair[i-1] + stair[i])

print(dp[n])