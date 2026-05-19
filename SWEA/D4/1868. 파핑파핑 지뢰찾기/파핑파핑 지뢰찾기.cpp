#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;
vector<string> board;
vector<vector<int>> mineCnt;
vector<vector<bool>> visited;

int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool inRange(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

void bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (mineCnt[y][x] != 0) continue;

        for (int dir = 0; dir < 8; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (!inRange(ny, nx)) continue;
            if (visited[ny][nx]) continue;
            if (board[ny][nx] == '*') continue;

            visited[ny][nx] = true;

            if (mineCnt[ny][nx] == 0) {
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N;

        board.assign(N, "");
        mineCnt.assign(N, vector<int>(N, 0));
        visited.assign(N, vector<bool>(N, false));

        for (int i = 0; i < N; i++) {
            cin >> board[i];
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (board[y][x] == '*') continue;

                for (int dir = 0; dir < 8; dir++) {
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    if (inRange(ny, nx) && board[ny][nx] == '*') {
                        mineCnt[y][x]++;
                    }
                }
            }
        }

        int answer = 0;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (board[y][x] == '.' && !visited[y][x] && mineCnt[y][x] == 0) {
                    bfs(y, x);
                    answer++;
                }
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (board[y][x] == '.' && !visited[y][x]) {
                    answer++;
                }
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}