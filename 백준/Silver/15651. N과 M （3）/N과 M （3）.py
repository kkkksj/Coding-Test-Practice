import sys
n, m = map(int, sys.stdin.readline().split())
answer = []

def back(answer, m, n):
    if len(answer) == m: #받은 배열이 m길이가 되면
        print(*answer) #출력
        return
    else:
        for i in range(1, n+1): #증가시키면서
            answer.append(i) #배열에 추가
            back(answer, m, n) #추가된 배열로 다시 호출
            del answer[-1] #위의 if문에서 리턴을 타고 오면 여기로 옴, 마지막 원소를 지움
back(answer, m, n)