import sys
sum_mushroom = 0

for i in range(10):
    mushroom = int(sys.stdin.readline())
    if sum_mushroom + mushroom >= 100:
        if 100 - sum_mushroom >= sum_mushroom+mushroom - 100:
            sum_mushroom += mushroom
        break
    else:
        sum_mushroom += mushroom
print(sum_mushroom)