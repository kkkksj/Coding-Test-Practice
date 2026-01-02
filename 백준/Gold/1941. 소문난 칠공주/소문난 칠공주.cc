#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n = 5;
vector<string> grid (n, "");
vector<int> pick;
vector<bool> selected(25, false);
vector<int> i_list = { -1, 1, 0, 0 };
vector<int> j_list = { 0, 0, -1, 1 };
int ans = 0;

bool IsRight() {
	int cnt = 0;
	for (int num : pick) {
		int i = num / 5;
		int j = num % 5;
		if (grid[i][j] == 'S')
			cnt++;
	}
	if (cnt >= 4)
		return true;
	return false;
}

bool IsConnected() {
	queue<int> q;
	vector<bool> visited(25, false);
	q.push(pick[0]);
	visited[pick[0]] = true;
	int cnt = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int i = now / 5;
		int j = now % 5;

		for (int d = 0; d < 4; d++) {
			int next_i = i + i_list[d];
			int next_j = j + j_list[d];
			if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n)
				continue;
			int next = next_i * 5 + next_j;
			if (visited[next])
				continue;
			if (selected[next] == false)
				continue;

			visited[next] = true;
			q.push(next);
			cnt++;
		}
	}

	if (cnt == 7)
		return true;
	return false;
}

void Combi(int idx, int cnt) {
	if (cnt == 7) {
		if (IsRight() && IsConnected())
			ans++;
		return;
	}
	if (idx == 25)
		return;

	pick.push_back(idx);
	selected[idx] = true;
	Combi(idx + 1, cnt + 1);
	pick.pop_back();
	selected[idx] = false;
	Combi(idx + 1, cnt);
}

int main() {
	for (int i = 0; i < n; i++)
		cin >> grid[i];

	Combi(0, 0);

	cout << ans << '\n';
}