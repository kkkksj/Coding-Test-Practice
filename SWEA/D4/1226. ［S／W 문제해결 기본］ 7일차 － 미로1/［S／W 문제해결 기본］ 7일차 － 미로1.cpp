#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<string> maze;
vector<int> i_list = { 0, 0, -1, 1 };
vector<int> j_list = { -1, 1, 0, 0 };

bool BFS(int si, int sj, int ei, int ej) {
	vector<vector<bool>> visited(16, vector<bool>(16, false));
	queue<pair<int, int>> q;
	visited[si][sj] = true;
	q.push({ si, sj });

	while (!q.empty()) {
		int now_i = q.front().first;
		int now_j = q.front().second;

		if (now_i == ei && now_j == ej)
			return 1;

		q.pop();

		for (int d = 0; d < 4; d++) {
			int next_i = now_i + i_list[d];
			int next_j = now_j + j_list[d];
			if (next_i < 0 || next_i >= 16 || next_j < 0 || next_j >= 16 || visited[next_i][next_j])
				continue;
			if (maze[next_i][next_j] == '1')
				continue;

			visited[next_i][next_j] = true;
			q.push({ next_i, next_j });
		}
	}

	return 0;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int tc;
		cin >> tc;

		int si, sj, ei, ej;
		maze.assign(16, "");
		for (int i = 0; i < 16; i++) {
			cin >> maze[i];
			for (int j = 0; j < 16; j++) {
				if (maze[i][j] == '2') {
					si = i;	sj = j;
				}
				else if (maze[i][j] == '3') {
					ei = i;	ej = j;
				}
			}
		}

		cout << '#' << test_case << ' ' << BFS(si, sj, ei, ej) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}