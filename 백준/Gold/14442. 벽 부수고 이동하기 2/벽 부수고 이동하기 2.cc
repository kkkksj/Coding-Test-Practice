#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int n, m, k;
vector<string> grid;
vector<int> i_list = { -1, 1, 0, 0 };
vector<int> j_list = { 0, 0, -1, 1 };

struct Info {
	int i, j, broken;
};

int BFS() {
	vector<vector<vector<int>>> dist (n, vector<vector<int>> (m, vector<int> (k+1, 0)));
	queue<Info> q;
	dist[0][0][0] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		int now_i = q.front().i;
		int now_j = q.front().j;
		int broken = q.front().broken;
		q.pop();

		if (now_i == n - 1 && now_j == m - 1)
			return dist[now_i][now_j][broken];

		for (int d = 0; d < 4; d++) {
			int next_i = now_i + i_list[d];
			int next_j = now_j + j_list[d];

			if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m)
				continue;

			if (grid[next_i][next_j] == '1' && broken < k && dist[next_i][next_j][broken + 1] == 0) {
				dist[next_i][next_j][broken + 1] = dist[now_i][now_j][broken] + 1;
				q.push({ next_i, next_j, broken + 1 });
			}
			else if (grid[next_i][next_j] == '0' && dist[next_i][next_j][broken] == 0) {
				dist[next_i][next_j][broken] = dist[now_i][now_j][broken] + 1;
				q.push({ next_i, next_j, broken });
			}
		}
	}

	return -1;
}

int main() {
	cin >> n >> m >> k;
	grid.assign(n, "");

	for (int i = 0; i < n; i++)
		cin >> grid[i];

	cout << BFS() << '\n';
}