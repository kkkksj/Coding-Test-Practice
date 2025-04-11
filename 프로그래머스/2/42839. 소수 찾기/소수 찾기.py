from itertools import permutations

def IsPrime(num):
    if num < 2:
        return False
    for i in range(2, num//2 + 1):
        if num % i == 0:
            return False
    return True

def solution(numbers):
    answer = 0
    number_list = []
    for n in range(1, len(numbers)+1):
        comb_list = permutations(list(numbers), n)
        for comb in comb_list:
            number_list.append(int(''.join(comb)))
        number_list = list(set(number_list))
    for num in number_list:
        if IsPrime(num):
            answer += 1
            
    return answer