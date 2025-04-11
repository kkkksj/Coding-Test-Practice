def solution(sizes):
    answer = 0
    
    for i in range(len(sizes)):
        if sizes[i][0] < sizes[i][1]:
            temp = sizes[i][0]
            sizes[i][0] = sizes[i][1]
            sizes[i][1] = temp
    garo = max([arr[0] for arr in sizes])
    sero = max([arr[1] for arr in sizes])            
    
    answer = garo * sero
    return answer