import sys
n, m = map(int, sys.stdin.readline().split())
answer = []
idx = 0 #answer에 요소가 추가될 위치를 가리키는 변수

def back(answer, m, n, idx):
    if len(answer) == m: #받은 배열이 m길이가 되면
        print(*answer) #출력
        return
    else:
        for i in range(1, n+1): #증가시키면서
            if (idx == 0) or (answer[idx-1] < i) : #answer이 비어있거나 바로 앞의 수보다 지금 추가될 수가 더 클 때만
                answer.append(i) #배열에 추가
                idx += 1 #위치를 +1
                back(answer, m, n, idx) #추가된 배열로 다시 호출
                del answer[-1] #위의 if문에서 리턴을 타고 오면 여기로 옴, 마지막 원소를 지움
                idx -= 1 #위치를 -1
back(answer, m, n, idx)