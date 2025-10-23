def solution(triangle):
    answer = 0
    n = len(triangle)
    prev = [0] * n
    curr = [0] * n
    
    for i in range(n):
        for j in range(i+1):
            if j==0:
                curr[j] = prev[0] + triangle[i][j]
            elif j==i:
                curr[j] = prev[j-1] + triangle[i][j]
            else:
                curr[j] = max(prev[j-1],prev[j]) + triangle[i][j]
                
        for i in range(n):
            prev[i] = curr[i]
        
    answer = max(prev)
    return answer