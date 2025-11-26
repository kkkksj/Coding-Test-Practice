#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> dp;
vector<vector<int>> grid;
vector<int> i_list = { -1, 1, 0, 0 };
vector<int> j_list = { 0, 0, -1, 1 };

int DFS(int i, int j) {
	if (i == n - 1 && j == m - 1)
		return 1;
	if (dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = 0;
	for (int d = 0; d < 4; d++) {
		int next_i = i + i_list[d];
		int next_j = j + j_list[d];

		if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m)
			continue;
		if (grid[next_i][next_j] < grid[i][j])
			dp[i][j] += DFS(next_i, next_j);
	}
	return dp[i][j];
}

int main()
{
	cin >> n >> m;
	grid.assign(n, vector<int>(m, 0));
	dp.assign(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];

	cout << DFS(0, 0) << '\n';
}