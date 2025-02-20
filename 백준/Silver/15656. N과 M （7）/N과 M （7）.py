n, m = map(int, input().split())
num_list = list(map(int, input().split()))
num_list.sort()
answer = []

def n_and_m(answer, m, n):
    if len(answer) == m:
        print(*answer)
        return
    else:
        for i in range(n):
            answer.append(num_list[i])
            n_and_m(answer, m, n)
            del answer[-1]

n_and_m(answer, m, n)