def Check(board_list):
    cnt1 = 0
    cnt2 = 0
    for i in range(8): #첫 시작이 White
        if i % 2 == 0:
            test = 'WBWBWBWB'
            for j in range(8):
                if test[j] != board_list[i][j]:
                    cnt1 += 1
                else:
                    cnt2 += 1
        else:
            test = 'BWBWBWBW'
            for j in range(8):
                if test[j] != board_list[i][j]:
                    cnt1 += 1
                else:
                    cnt2 += 1
    return cnt1 if cnt1 <= cnt2 else cnt2

import sys
n, m = map(int, input().split())
board = []
eight_board = []
min_cnt = 2500

for i in range(n):
    board.append(sys.stdin.readline().rstrip())

for col in range(n - 7):
    for row in range(m - 7):
        eight_board = list(i[row:row+8] for i in board[col:col+8])
        cnt = Check(eight_board)
        min_cnt = min_cnt if min_cnt <= cnt else cnt
print(min_cnt)