n, k = map(int, input().split())

temp_list = list(map(int, input().split()))

sum_temp_list = [0 for i in range(n+1)]

for i in range(1, n+1):
    sum_temp_list[i] = sum_temp_list[i-1] + temp_list[i-1]

max =  sum_temp_list[k]
for i in range(k, n+1):
    temp_sum = sum_temp_list[i] - sum_temp_list[i-k]
    max = temp_sum if max < temp_sum else max

print(max)