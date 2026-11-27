#include <iostream>
#include <algorithm>

#define MAXN 101
#define INF 1000000000

using namespace std;

int n, m;
int cost[MAXN][MAXN];
int short_cost[MAXN][MAXN];

void Floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (short_cost[i][k] == INF || short_cost[k][j] == INF)
                    continue;

                short_cost[i][j] = min(short_cost[i][j],
                    short_cost[i][k] + short_cost[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = INF;

            if (i == j)
                cost[i][j] = 0;
        }
    }

    int a, b, c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            short_cost[i][j] = cost[i][j];
        }
    }

    Floyd();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (short_cost[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << short_cost[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}