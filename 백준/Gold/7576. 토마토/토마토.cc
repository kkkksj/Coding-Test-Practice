#include <iostream>
#include <queue>

#define MAXN 1000

using namespace std;

struct Node {
    int r;
    int c;
};

int n, m;
int board[MAXN][MAXN];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    cin >> m >> n;

    queue<Node> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] == 1)
                q.push({i, j});
        }
    }

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = now.r + dr[dir];
            int nc = now.c + dc[dir];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            if (board[nr][nc] != 0)
                continue;

            board[nr][nc] = board[now.r][now.c] + 1;
            q.push({nr, nc});
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                cout << -1;
                return 0;
            }

            if (board[i][j] > answer)
                answer = board[i][j];
        }
    }

    cout << answer - 1 << '\n';

    return 0;
}