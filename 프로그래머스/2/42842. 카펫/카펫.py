def solution(brown, yellow):
    answer = []
    for i in range(1, int(yellow**0.5 + 1)):
        if yellow % i == 0:
            j = yellow // i
            if (i+2)*2 + j*2 == brown:
                answer = [j+2, i+2]
                break
    return answer