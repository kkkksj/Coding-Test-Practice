#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int n;
vector<string> grid;
vector<int> i_list = { 0, 1, 0, -1};
vector<int> j_list = { 1, 0, -1, 0 };

struct Info {
	int w;
	int i, j;
};

struct CMP{
	bool operator() (Info a, Info b) {
		if (a.w != b.w)
			return a.w > b.w;
		if (a.i != b.i)
			return a.i > b.i;
		return a.j > b.j;
	}
};

int BFS() {
	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
	priority_queue < Info, vector<Info>, CMP> q;
	dist[0][0] = grid[0][0] - '0';
	q.push({ dist[0][0], 0, 0 });

	while (!q.empty()) {
		int now_i = q.top().i;
		int now_j = q.top().j;
		int weight = q.top().w;
		q.pop();

		if (now_i == n - 1 && now_j == n - 1)
			return weight;
		for (int d = 0; d < 4; d++) {
			int next_i = now_i + i_list[d];
			int next_j = now_j + j_list[d];
			if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n)
				continue;
			if (dist[next_i][next_j] <= weight + (grid[next_i][next_j] - '0'))
				continue;
			dist[next_i][next_j] = weight + (grid[next_i][next_j] - '0');
			q.push({ dist[next_i][next_j], next_i, next_j });
		}
	}
	return dist[n - 1][n - 1];
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		grid.assign(n, "");
		for (int i = 0; i < n; i++)
			cin >> grid[i];

		cout << '#' << test_case << ' ' << BFS() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}