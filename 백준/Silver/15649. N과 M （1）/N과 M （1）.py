"""
배열 길이가 m이 됐을 때 answer에서 마지막 요소를 빼서
다시 back을 호출하는 방법으로하니까 무한 굴레에 빠져부림
도저히 이 처리를 어케해야될지 몰라서 이건 인터넷을 찾아봤음
(이게 포인트인 듯..?)
백트래킹 공부해야지.........엉엉
"""
import sys
n, m = map(int, sys.stdin.readline().split())
answer = []

def back(answer, m, n):
    if len(answer) == m: #받은 배열이 m길이가 되면
        print(*answer) #출력
        return 
    else:
        for i in range(1, n+1): #증가시키면서
            if i not in answer: #answer배열에 없으면
                answer.append(i) #배열에 추가
                back(answer, m, n) #추가된 배열로 다시 호출
                del answer[-1] #위의 if문에서 리턴을 타고 오면 여기로 옴, 마지막 원소를 지움
back(answer, m, n)