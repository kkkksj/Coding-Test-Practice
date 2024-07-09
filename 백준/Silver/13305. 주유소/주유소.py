n = int(input())
distance_list = list(map(int, input().split()))
oil_list = list(map(int, input().split()))

#각 첫 원소로 초기화
distance = distance_list[0]
oil = oil_list[0]
total_price = oil * distance
pre_price = 0

for i in range(1, n-1):
    new_oil = oil_list[i]
    new_distance = distance_list[i]

    #기존 가격에 새오일가격으로 앞으로의 거리를 가는 것이 기존 오일 가격으로 이 전의 거리 + 앞으로의 거리를 가는 것보다 저렴하면
    #즉 새로운 오일로 갈아타는게 저렴하면
    if total_price + new_oil*new_distance < pre_price + oil*(distance + new_distance):
        pre_price = total_price #지금까지 돈을 저장해 둠
        total_price = total_price + new_oil * new_distance #토탈 돈은 업데이트 
        oil = new_oil #바로 직전에 사용한 오일 업데이트
        distance = new_distance #다음 비교에 사용될 거리를 새로 업데이트
    else: #기존 오일을 사용하는게 저렴하면
        total_price = pre_price + oil * (distance + new_distance) #토탈 가격은 이전 가격에 기존 오일로 계산한 가격
        distance = distance + new_distance #다음 비교에 사용될 거리는 기존 + 새롭게 온 거리
print(total_price)
#(뭔가 주석으로 쓰기에 너무 어렵다.. 잘 이해가 안 되고 궁금하다면 물어보십쇼!!)