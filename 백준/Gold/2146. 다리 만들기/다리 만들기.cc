#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int n;
vector<vector<int>> grid;
vector<int> i_list = { -1, 1, 0, 0 };
vector<int> j_list = { 0, 0, -1, 1 };
int ans = INT_MAX;

void BFS(int i, int j, int num) {
	grid[i][j] = num;
	queue<pair<int, int>> q;
	q.push({ i, j });
	
	while (!q.empty()) {
		int now_i = q.front().first;
		int now_j = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int next_i = now_i + i_list[d];
			int next_j = now_j + j_list[d];

			if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n)
				continue;
			if (grid[next_i][next_j] == 1) {
				grid[next_i][next_j] = num;
				q.push({ next_i, next_j });
			}
		}
	}
}

int Dist(int i, int j) {
	int num = grid[i][j];
	vector<vector<int>> dist(n, vector<int>(n, -1));
	queue<pair<int, int>> q;
	dist[i][j] = 0;
	q.push({ i, j });

	while (!q.empty()) {
		int now_i = q.front().first;
		int now_j = q.front().second;
		q.pop();
		if (grid[now_i][now_j] != 0 && grid[now_i][now_j] != num)
			return dist[now_i][now_j];
		for (int d = 0; d < 4; d++) {
			int next_i = now_i + i_list[d];
			int next_j = now_j + j_list[d];

			if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n)
				continue;
			if (grid[next_i][next_j] != num && dist[next_i][next_j] == -1) {
				dist[next_i][next_j] = dist[now_i][now_j] + 1;
				q.push({ next_i, next_j });
			}
		}
	}
	return -1;
}

void Search() {
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0)
				continue;
			for (int d = 0; d < 4; d++) {
				int ni = i + i_list[d];
				int nj = j + j_list[d];
				if (ni < 0 || ni >= n || nj < 0 || nj >= n)
					continue;
				if (grid[ni][nj] == 0) {
					int dd = Dist(i, j);
					if (dd == -1)
						continue;
					ans = min(dd, ans);
					break;
				}
			}
		}
}

int main()
{
	cin >> n;
	grid.assign(n, vector<int>(n));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];

	int num = 2;
	for(int i=0; i<n; i++) {
		for (int j = 0; j < n; j++) 
			if (grid[i][j] == 1) {
				BFS(i, j, num);
				num++;
			}
	}

	Search();

	cout << ans-1 << '\n';
}