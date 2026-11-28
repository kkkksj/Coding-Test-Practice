#include <iostream>
#include <queue>
#include <algorithm>

#define MAXN 1000

using namespace std;

struct Info {
    int i, j, day;
};

int n, m;
int board[MAXN][MAXN];

int i_list[4] = {-1, 1, 0, 0};
int j_list[4] = {0, 0, -1, 1};

queue<Info> q;

int BFS(int cnt) {
    int answer = 0;

    while (!q.empty()) {
        Info now = q.front();
        q.pop();

        answer = max(answer, now.day);

        for (int d = 0; d < 4; d++) {
            int nexti = now.i + i_list[d];
            int nextj = now.j + j_list[d];

            if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m)
                continue;

            if (board[nexti][nextj] != 0)
                continue;

            board[nexti][nextj] = 1;
            cnt--;

            q.push({nexti, nextj, now.day + 1});
        }
    }

    if (cnt > 0)
        return -1;

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] == 1)
                q.push({i, j, 0});

            if (board[i][j] == 0)
                cnt++;
        }
    }

    cout << BFS(cnt) << '\n';

    return 0;
}