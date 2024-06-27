import sys
n, m = map(int, sys.stdin.readline().split())
answer = []
idx = 1 #시작 범위가 될 변수

def back(answer, m, n, idx):
    if len(answer) == m: #받은 배열이 m길이가 되면
        print(*answer) #출력
        return
    else:
        for i in range(idx, n+1): #증가시키면서
            idx = i + 1 #idx부터 시작할 수 있도록 업데이트
            answer.append(i) #배열에 추가
            back(answer, m, n, idx) #추가된 배열로 다시 호출
            del answer[-1] #위의 if문에서 리턴을 타고 오면 여기로 옴, 마지막 원소를 지움
back(answer, m, n, idx)