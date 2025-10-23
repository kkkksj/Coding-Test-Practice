import heapq

def solution(n, works):
    answer = 0
    if sum(works) < n:
        return 0
    
    hq = []
    for w in works:
        heapq.heappush(hq, -w)
    for i in range(n):
        t = heapq.heappop(hq)
        t += 1
        heapq.heappush(hq, t)
    
    for num in hq:
        answer += (num*num)
    return answer