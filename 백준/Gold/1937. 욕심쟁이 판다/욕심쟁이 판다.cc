#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> grid;
vector<int> i_list = { -1, 1, 0, 0 };
vector<int> j_list = { 0, 0, -1, 1 };
vector<vector<int>> dist;

int DFS(int i, int j) {
	int& ret = dist[i][j];
	if (ret != -1) return ret; 

	ret = 1; 

	for (int d = 0; d < 4; d++) {
		int ni = i + i_list[d];
		int nj = j + j_list[d];

		if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
		if (grid[ni][nj] <= grid[i][j]) continue; 

		ret = max(ret, 1 + DFS(ni, nj));
	}

	return ret;
}

int main()
{
	cin >> n;
	grid.assign(n, vector<int>(n));
	dist.assign(n, vector<int>(n, -1));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
				ans = max(ans, DFS(i, j));
		
	cout << ans << '\n';
}