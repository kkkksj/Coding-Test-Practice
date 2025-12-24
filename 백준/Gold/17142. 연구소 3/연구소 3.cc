#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int n, m;
int ttl;
vector<vector<int>> grid;
vector<pair<int, int>> virus_candidate;
vector<pair<int, int>> pick;
vector<int> i_list = { -1, 1, 0, 0 };
vector<int> j_list = { 0, 0, -1, 1 };
int ans = INT_MAX;

int BFS() {
	queue<pair<int, int>> q;
	vector<vector<int>> time(n, vector<int>(n, -1));
	for (int i = 0; i < m; i++) {
		q.push({ pick[i].first, pick[i].second });
		time[pick[i].first][pick[i].second] = 0;
	}
	
	int ret = 0;
	int cnt = 0;
	while (!q.empty()) {
		int now_i = q.front().first;
		int now_j = q.front().second;
		int t = time[now_i][now_j];
		q.pop();

		for (int d = 0; d < 4; d++) {
			int next_i = now_i + i_list[d];
			int next_j = now_j + j_list[d];

			if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n || time[next_i][next_j] != -1)
				continue;
			if (grid[next_i][next_j] == 1)
				continue;
			time[next_i][next_j] = t + 1;
			q.push({ next_i, next_j });

			if (grid[next_i][next_j] == 0) {
				cnt++;
				ret = time[next_i][next_j];
			}
			if (cnt == ttl)
				return ret;
		}
		if (cnt == ttl)
			return ret;
	}

	return -1;
}

void Pick(int start) {
	if (pick.size() == m) {
		int ret = BFS();
		if(ret != -1)
			ans = min(ret, ans);
		return;
	}
	for (int i = start; i < virus_candidate.size(); i++) {
		pick.push_back({ virus_candidate[i].first, virus_candidate[i].second });
		Pick(i + 1);
		pick.pop_back();
	}
}

int main() {
	cin >> n >> m;
	grid.assign(n, vector<int>(n));
	ttl = 0;

	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 0)
				ttl++;
			if (grid[i][j] == 2)
				virus_candidate.push_back({ i, j });
		}

	Pick(0);

	if (ans == INT_MAX)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}