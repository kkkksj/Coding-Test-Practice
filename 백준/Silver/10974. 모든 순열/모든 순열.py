n = int(input())
answer = []

def n_and_m(answer, n):
    if len(answer) == n:
        print(*answer)
        return
    else:
        for num in range(1, n+1):
            if len(answer) == 0 or num not in answer:
                answer.append(num)
                n_and_m(answer, n)
                del answer[-1]

n_and_m(answer, n)