n = list(input())
n.sort(reverse=True)
int_n = list(map(int, n))

if int_n[-1] == 0 and sum(int_n) % 3 == 0:
    print(''.join(n))
else:
    print(-1)