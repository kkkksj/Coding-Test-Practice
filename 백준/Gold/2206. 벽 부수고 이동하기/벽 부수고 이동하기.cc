#include <iostream>
#include <string>
#include <queue>

#define MAXN 1000

using namespace std;

string grid[MAXN];
bool visited[MAXN][MAXN][2];

int n, m;
int i_list[4] = {-1, 1, 0, 0};
int j_list[4] = {0, 0, -1, 1};

struct Info {
    int i, j, cnt;
    bool crashed;
};

int Search() {
    queue<Info> q;

    q.push({0, 0, 1, false});
    visited[0][0][0] = true;

    while (!q.empty()) {
        Info now = q.front();
        q.pop();

        if (now.i == n - 1 && now.j == m - 1)
            return now.cnt;

        for (int d = 0; d < 4; d++) {
            int nexti = now.i + i_list[d];
            int nextj = now.j + j_list[d];

            if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m)
                continue;

            if (grid[nexti][nextj] == '1' && !now.crashed) {
                if (visited[nexti][nextj][1])
                    continue;

                q.push({nexti, nextj, now.cnt + 1, true});
                visited[nexti][nextj][1] = true;
            }
            else if (grid[nexti][nextj] == '0') {
                if (visited[nexti][nextj][now.crashed])
                    continue;

                q.push({nexti, nextj, now.cnt + 1, now.crashed});
                visited[nexti][nextj][now.crashed] = true;
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    cout << Search() << '\n';

    return 0;
}