import sys
import math
from collections import defaultdict
n = int(input())
num_dic = defaultdict(int) #최빈값 저장을 위한 딕셔너리
num_list = [0] * n #나머지 연산을 위한 리스트

for i in range(n):
    number = int(sys.stdin.readline())
    num_dic[number] += 1 #딕셔너리에 입력 횟수 저장
    num_list[i] = number
num_list.sort() #오름차순 정렬
num_dic = sorted(num_dic.items(), key=lambda x:(-x[1], x[0])) #딕셔너리 value는 내림차순, key는 오름차순으로 정렬

print(round(sum(num_list)/n))
print(num_list[int(n/2)])
if n==1: #수가 하나면 그냥 그거 출력
    print(num_dic[0][0])
else: 
    #가장 처음과 바로 그 다음이 같으면(최빈값이 두개이상) 두번째 수 출력
    #최빈값이 하나면 그냥 그거 출력
    print(num_dic[0][0] if num_dic[0][1] != num_dic[1][1] else num_dic[1][0])
print(num_list[-1] - num_list[0])