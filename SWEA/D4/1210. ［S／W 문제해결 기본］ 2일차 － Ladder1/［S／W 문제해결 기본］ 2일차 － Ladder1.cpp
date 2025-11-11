#include<iostream>
#include<vector>

using namespace std;

int n = 100;
vector<vector<int>> grid;
int ans = 0;
vector<int> i_list = { 0, 0, -1 };
vector<int> j_list = { -1, 1, 0 };

void DFS(int i, int j) {
	if (i == 0) {
		ans = j;
		return;
	}
	for (int d = 0; d < 3; d++) {
		int next_i = i + i_list[d];
		int next_j = j + j_list[d];
		if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n || grid[next_i][next_j] == 0 )
			continue;
		grid[next_i][next_j] = 0;
		DFS(next_i, next_j);
		break;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int tc;
		cin >> tc;
		grid.assign(n, vector<int>(n, 0));
		ans = 0;

		int si = 0, sj = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 2) {
					si = i;
					sj = j;
				}
			}

		DFS(si, sj);

		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}