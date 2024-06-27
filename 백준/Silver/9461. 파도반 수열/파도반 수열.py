"""
이것도 DP이므로 규칙을 찾았습니다.
p(12)까지 해본 결과 p(n)은 p(n-1)과 p(n-5)의 합이라는 것을 알았읍니다.
"""
import sys
n = int(input())
semo = [0] * 101
semo[:11] = [0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9] #초기배열

for i in range(n):
    num = int(sys.stdin.readline())

    if num <= 10:
        print(semo[num]) #10보다 작다면 초기 배열에서 출력
    else:
        for j in range(11, num+1):
            semo[j] = semo[j-1] + semo[j-5] #현재는 이전 것 + 다섯번째 전 것
        print(semo[num])