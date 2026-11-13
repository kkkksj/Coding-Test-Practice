#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
int board[12];

bool Check(int row) {
    for (int i = 0; i < row; i++) {
        if (board[i] == board[row])
            return false;

        if (abs(board[i] - board[row]) == abs(i - row))
            return false;
    }

    return true;
}

void DFS(int row, int n) {
    if (row == n) {
        answer++;
        return;
    }

    for (int col = 0; col < n; col++) {
        board[row] = col;

        if (Check(row))
            DFS(row + 1, n);
    }
}

int solution(int n) {
    DFS(0, n);

    return answer;
}