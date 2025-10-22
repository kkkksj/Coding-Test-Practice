import sys
input = sys.stdin.readline

n = int(input())
timetable = []
for i in range(n):
    timetable.append(list(map(int, input().split())))

timetable.sort(key=lambda x:(x[1], x[0]))

min_start = timetable[0][1]
ans = 1
for i in range(1, n):
    if timetable[i][0] >= min_start:
        min_start = timetable[i][1]
        ans += 1

print(ans)