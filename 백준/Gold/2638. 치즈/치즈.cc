#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<int> i_list = { -1, 1, 0, 0 };
vector<int> j_list = { 0, 0, -1, 1 };
queue<pair<int, int>> pos;

void Outside(int i, int j) {
	grid[i][j] = 2;
	queue<pair<int, int>> q;
	q.push({ i, j });

	while (!q.empty()) {
		int now_i = q.front().first;
		int now_j = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int next_i = now_i + i_list[d];
			int next_j = now_j + j_list[d];

			if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m )
				continue;
			if(grid[next_i][next_j] == 0) {
				grid[next_i][next_j] = 2;
				q.push({ next_i, next_j });
			}
		}
	}
}

bool IsOutside(int i, int j) {
	for (int d = 0; d < 4; d++) {
		int t = 1;
		while (t < max(n, m)) {
			int next_i = i + i_list[d] * t;
			int next_j = j + j_list[d] * t;
			if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m)
				return true;
			if (grid[next_i][next_j] == 1)
				break;
			t++;
		}
	}
	return false;
}

void Check() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j]==0 && IsOutside(i, j)) {
				Outside(i, j);
				return;
			}
}

bool Check4Side(int i, int j) {
	int cnt = 0;
	for (int d = 0; d < 4; d++) {
		int next_i = i + i_list[d];
		int next_j = j + j_list[d];
		if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m || grid[next_i][next_j] == 2)
			cnt++;
		if (cnt >= 2) {
			pos.push({ i, j });
			return true;
		}
	}
	return false;
}

struct Info {
	int i, j, time;
};

int main()
{
	cin >> n >> m;
	grid.assign(n, vector<int>(m));

	queue<Info> cheese;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1)
				cheese.push({ i, j, 1 });
		}

	Check();

	int ans = 0;
	while (!cheese.empty()) {
		int i = cheese.front().i;
		int j = cheese.front().j;
		int time = cheese.front().time;
		cheese.pop();
		
		if (Check4Side(i, j))
			ans = max(ans, time);
		else
			cheese.push({ i, j, time + 1 });

		if (!cheese.empty() && cheese.front().time != time)
			while (!pos.empty()) {
				int ti = pos.front().first;
				int tj = pos.front().second;
				pos.pop();
				Outside(ti, tj);
			}
	}

	cout << ans << '\n';
}