#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n, l;
vector<vector<int>> grid;

bool CheckRow(int c) {
	int now_h = grid[0][c];
	int i = 0;
	vector<bool> slope(n, false);
	while(i < n-1) {
		i++;
		if (grid[i][c] == now_h)
			continue;
		int gap = grid[i][c] - now_h;
		now_h += gap;
		if (gap == -1) {
			int cnt = 1;
			while (cnt < l) {
				i++;
				if (i >= n || grid[i][c] != now_h)
					return false;
				cnt++;
			}
			slope[i] = true;
		}
		else if (gap == 1) {
			int cnt = 0;
			int tmp = i;
			while (cnt < l) {
				tmp--;
				if (tmp < 0 || grid[tmp][c] != now_h - 1 || slope[tmp])
					return false;
				cnt++;
			}
		}
		else
			return false;

	}
	return true;
}

bool CheckCol(int r) {
	int now_h = grid[r][0];
	int i = 0;
	vector<bool> slope(n, false);
	while (i < n - 1) {
		i++;
		if (grid[r][i] == now_h)
			continue;
		int gap = grid[r][i] - now_h;
		now_h += gap;
		if (gap == -1) {
			int cnt = 1;
			while (cnt < l) {
				i++;
				if (i >= n || grid[r][i] != now_h)
					return false;
				cnt++;
			}
			slope[i] = true;
		}
		else if (gap == 1) {
			int cnt = 0;
			int tmp = i;
			while (cnt < l) {
				tmp--;
				if (tmp < 0 || grid[r][tmp] != now_h - 1 || slope[tmp])
					return false;
				cnt++;
			}
		}
		else
			return false;

	}
	return true;
}


int main()
{
	cin >> n >> l;
	grid.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (CheckRow(i))
			ans++;
		if (CheckCol(i))
			ans++;
	}

	cout << ans << '\n';
}