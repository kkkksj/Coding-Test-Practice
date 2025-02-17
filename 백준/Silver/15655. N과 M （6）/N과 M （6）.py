N, M = map(int, input().split())

num_list = list(map(int, input().split()))
num_list.sort()

answer = []
def back(answer, m, n):
    if len(answer) == m:
        print(*answer)
        return
    else:
        for i in range(n):
            if len(answer) == 0 or answer[-1] < num_list[i]:
                answer.append(num_list[i])
                back(answer, m, n)
                del answer[-1]

back(answer, M, N)