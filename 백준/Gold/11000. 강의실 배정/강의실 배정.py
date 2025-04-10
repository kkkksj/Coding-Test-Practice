import sys
import heapq
input = sys.stdin.readline

n = int(input())
class_time = []
for i in range(n):
    class_time.append(list(map(int, input().split())))
class_time.sort()

heap = [class_time[0][1]]
for i in range(1, n):
    if heap[0] <= class_time[i][0]:
        heapq.heappop(heap)
    heapq.heappush(heap, class_time[i][1])
print(len(heap))