#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K, W, H;
vector<vector<int>> grid;
int dist[201][201][31];  // [y][x][말 점프 사용 횟수]

int dy4[4] = { -1, 1, 0, 0 };
int dx4[4] = { 0, 0, -1, 1 };

int dy8[8] = { -2,-2,-1,-1, 1, 1, 2, 2 };
int dx8[8] = { -1, 1,-2, 2,-2, 2,-1, 1 };

struct Node {
    int y, x, k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> W >> H;
    grid.assign(H, vector<int>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> grid[i][j];

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            for (int k = 0; k <= K; k++)
                dist[i][j][k] = -1;

    queue<Node> q;
    dist[0][0][0] = 0;
    q.push({ 0, 0, 0 });

    while (!q.empty()) {
        auto [y, x, k] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = y + dy4[d];
            int nx = x + dx4[d];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (grid[ny][nx] == 1) continue; 
            if (dist[ny][nx][k] != -1) continue;

            dist[ny][nx][k] = dist[y][x][k] + 1;
            q.push({ ny, nx, k });
        }

        if (k < K) {
            for (int d = 0; d < 8; d++) {
                int ny = y + dy8[d];
                int nx = x + dx8[d];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if (grid[ny][nx] == 1) continue;
                if (dist[ny][nx][k + 1] != -1) 
                    continue;
                dist[ny][nx][k + 1] = dist[y][x][k] + 1;
                q.push({ ny, nx, k + 1 });
            }
        }
    }

    int ans = -1;
    for (int k = 0; k <= K; k++) {
        if (dist[H - 1][W - 1][k] == -1) 
            continue;
        if (ans == -1 || dist[H - 1][W - 1][k] < ans)
            ans = dist[H - 1][W - 1][k];
    }

    cout << ans << '\n';
    return 0;
}