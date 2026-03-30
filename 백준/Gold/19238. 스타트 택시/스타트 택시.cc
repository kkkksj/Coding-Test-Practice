#include <iostream>
#include <queue>

#define MAXN 20

using namespace std;

int n, m, oil;
int nowi, nowj;
int grid[MAXN + 1][MAXN + 1];
pair<int, int> dest_list[MAXN * MAXN + 10];
int visited[MAXN + 1][MAXN + 1];
int lazy = 0, clearnum = 0;
int i_list[4] = { -1, 0, 1, 0 };
int j_list[4] = { 0, -1, 0, 1 };

struct QInfo {
	int i, j, used_oil;

	bool operator<(const QInfo& right) const {
		if (used_oil != right.used_oil)
			return used_oil > right.used_oil;
		if (i != right.i)
			return i > right.i;
		return j > right.j;
	}
};

int BFS(int mode, int desti, int destj) {
	priority_queue<QInfo> q;
	q.push({ nowi, nowj, 0 });
	visited[nowi][nowj] = lazy;

	while (!q.empty()) {
		int i = q.top().i, j = q.top().j;
		int used_oil = q.top().used_oil;
		q.pop();

		if (mode == 0) {
			if (grid[i][j] >= 2) {
				nowi = i, nowj = j;
				return used_oil;
			}
		}
		else {
			if (i == desti && j == destj) {
				nowi = i, nowj = j;
				return used_oil;
			}
		}


		for (int d = 0; d < 4; d++) {
			int ni = i + i_list[d];
			int nj = j + j_list[d];
			int n_used = used_oil + 1;

			if (ni <= 0 || ni >= n+1 || nj <= 0 || nj >= n+1)
				continue;
			if (visited[ni][nj] == lazy || grid[ni][nj] == 1)
				continue;
			if (n_used > oil) 
				continue;

			q.push({ ni, nj, used_oil + 1 });
			visited[ni][nj] = lazy;
		}
	}

	return -1;
}

int play() {
	while (clearnum < m) {
		// 손님 찾으러 가기
		lazy++;
		int used_oil = BFS(0, -1, -1);
		
		// 손님 못 찾았으면 리턴
		if (used_oil == -1)
			return -1;
		int guest = grid[nowi][nowj];
		grid[nowi][nowj] = 0;

		// 오일 감소
		oil -= used_oil;

		// 목적지 데려다 주기
		lazy++;
		used_oil = BFS(1, dest_list[guest].first, dest_list[guest].second);

		// 못 데려다 주면 리턴 
		if (used_oil == -1)
			return -1;

		// 오일 충전 
		oil += used_oil;

		clearnum++;
	}
	return oil;
}

int main() {
	cin >> n >> m >> oil;

	for (int i = 1; i < n+1; i++)
		for (int j = 1; j < n+1; j++)
			cin >> grid[i][j];

	cin >> nowi >> nowj;

	for (int i = 2; i < m+2; i++) {
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		grid[i1][j1] = i;	// 승객
		dest_list[i] = { i2, j2 };	// 목적지 
	}

	int ret = play();

	cout << ret << '\n';
}