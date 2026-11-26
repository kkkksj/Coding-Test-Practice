#include <iostream>

#define MAXN 2187

using namespace std;

char board[MAXN][MAXN];

void DFS(int r, int c, int n) {
    if (n == 1) {
        board[r][c] = '*';
        return;
    }

    int next = n / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                continue;

            DFS(r + i * next, c + j * next, next);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = ' ';
        }
    }

    DFS(0, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}