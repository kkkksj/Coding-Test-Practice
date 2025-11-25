#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int n;
vector<vector<int>> grid;
vector<vector<int>> dist;
vector<int> i_list = { -1, 1, 0 ,0 };
vector<int> j_list = { 0 ,0, -1, 1 };
int shark_sz = 2;
int cnt = 0;
int shark_i, shark_j;
int ans = 0;

void Dist() {
	dist.assign(n, vector<int>(n, -1));
	queue<pair<int, int>> q;
	q.push({ shark_i, shark_j });
	dist[shark_i][shark_j] = 0;

	while(!q.empty()) {
		int now_i = q.front().first, now_j = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int next_i = now_i +i_list[d];
			int next_j = now_j + j_list[d];

			if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n || dist[next_i][next_j] != -1 || grid[next_i][next_j] > shark_sz)
				continue;

			dist[next_i][next_j] = dist[now_i][now_j] + 1;
			q.push({ next_i, next_j });
		}
	}
}

void Play() {
	while(true) {
		Dist();

		int move_i = -1, move_j = -1;
		int min_dist = INT_MAX;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0 || grid[i][j] >= shark_sz || (i == shark_i && j == shark_j))
					continue;
				if (dist[i][j] == -1)
					continue;
				if (dist[i][j] < min_dist) {
					move_i = i;
					move_j = j;
					min_dist = dist[i][j];
				}
			}
		if (move_i == -1 && move_j == -1)
			return;
		grid[shark_i][shark_j] = 0;
		grid[move_i][move_j] = 9;
		shark_i = move_i, shark_j = move_j;
		ans += min_dist;
		cnt++;
		if (cnt == shark_sz) {
			cnt = 0;
			shark_sz++;
		}
	}
}

int main()
{
	cin >> n;
	grid.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 9) {
				shark_i = i;
				shark_j = j;
			}
		}

	Play();

	cout << ans << '\n';
}