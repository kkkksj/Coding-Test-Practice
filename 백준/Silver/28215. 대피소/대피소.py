n, m = map(int, input().split())

xy_list = []
for i in range(n):
    xy_list.append(list(map(int, input().split())))

def cal_dist(x1, y1, x2, y2):
    return abs(x1-x2)+abs(y1-y2)

min_max_dist = 200000
if m == 1:
    for i in range(n):
        max_dist = 0
        for k in range(n):
            if k != i:
                dist = cal_dist(xy_list[i][0], xy_list[i][1], xy_list[k][0], xy_list[k][1])
                max_dist = max(max_dist, dist)
        min_max_dist = min(min_max_dist, max_dist)

elif m == 2:
    for i in range(n-1):
        for j in range(i+1, n):
            max_dist = 0
            for k in range(n):
                if k != i and k != j:
                    dist = min(cal_dist(xy_list[i][0], xy_list[i][1], xy_list[k][0], xy_list[k][1]),
                               cal_dist(xy_list[j][0], xy_list[j][1], xy_list[k][0], xy_list[k][1]))
                    max_dist = max(max_dist, dist)
            min_max_dist = min(min_max_dist, max_dist)

elif m == 3:
    for i in range(n-2):
        for j in range(i+1, n-1):
            for l in range(j+1, n):
                max_dist = 0
                for k in range(n):
                    if k != i and k != j and k != l:
                        dist = min(cal_dist(xy_list[i][0], xy_list[i][1], xy_list[k][0], xy_list[k][1]),
                                   cal_dist(xy_list[j][0], xy_list[j][1], xy_list[k][0], xy_list[k][1]),
                                   cal_dist(xy_list[l][0], xy_list[l][1], xy_list[k][0], xy_list[k][1]))
                        max_dist = max(max_dist, dist)
                min_max_dist = min(min_max_dist, max_dist)
print(min_max_dist)
