#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> grid;

int Sum(int r, int c) {
	int ret = 0;
	for (int i = r; i < r + m; i++)
		for (int j = c; j < c + m; j++)
			ret += grid[i][j];
	return ret;
}

int MaxFly() {
	int ans = 0;
	for (int i = 0; i < n - m + 1; i++)
		for (int j = 0; j < n - m + 1; j++)
			ans = max(ans, Sum(i, j));
	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		grid.assign(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> grid[i][j];

		cout << '#' << test_case << ' ' << MaxFly() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}