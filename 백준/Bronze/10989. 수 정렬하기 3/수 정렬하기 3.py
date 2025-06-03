import sys
n = int(input())
num_list = [0]
num_dic = {}

for i in range(n):
    num = int(sys.stdin.readline())
    if num in num_dic:
        num_dic[num] += 1
    else:
        num_dic[num] = 1
        for j in range(len(num_list)-1,-1,-1):
            if num_list[j] <= num:
                num_list.insert(j+1, num)
                break
for i in num_list[1:]:
    for j in range(num_dic[i]):
        print(i)