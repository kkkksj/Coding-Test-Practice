import sys
t = int(input())

for i in range(t):
    x1 ,y1, r1, x2, y2, r2 = map(int, sys.stdin.readline().split())

    minus_r = r1 - r2 if r1 > r2 else r2 - r1
    sum_r = r1 + r2
    d = ((x1-x2)**2 + (y1-y2)**2)**0.5
  
    if minus_r < d < sum_r: #원이 두 점에서 만나는 경우
        print(2)
    elif (d != 0 and sum_r == d) or (d != 0 and minus_r == d): #원이 한 점에서 만나는 경우
        print(1)
    elif (d == 0 and minus_r != 0) or sum_r < d or d < minus_r: #원이 하나도 안 만나는 경우
        print(0)
    elif d == 0 and minus_r == 0: #원이 완전히 겹치는 경우
        print(-1)