def FindRound(jimin, hansu, n):
    number = [i for i in range(1, n + 1)]
    for i in range(1, n):
        number.append(0)
        next_num = []
        for j in range(0, len(number)-1, 2):
            if (number[j] == jimin and number[j + 1] == hansu) or (number[j + 1] == jimin and number[j] == hansu):
                return i
            elif number[j + 1] == jimin:
                next_num.append(jimin)
            elif number[j + 1] == hansu:
                next_num.append(hansu)
            else:
                next_num.append(number[j])
        number[:] = next_num[:]
    return -1

n, jimin, hansu = map(int, input().split())
print(FindRound(jimin, hansu, n))