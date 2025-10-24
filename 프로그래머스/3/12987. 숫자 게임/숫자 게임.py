def solution(A, B):
    answer = 0
    A.sort()
    B.sort()
    
    n = len(A)
    t = n-1
    for i in range(n-1, -1, -1):
        if(A[i] < B[t]):
            answer += 1
            t -= 1
            
    return answer