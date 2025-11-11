#include<iostream>
#include<vector>

using namespace std;

int n = 9;
vector<vector<int>> grid;

bool CheckSquare(int r, int c) {
	vector<bool> visited(10, false);
	for (int i = r; i < r + 3; i++)
		for (int j = c; j < c + 3; j++){
			if (visited[grid[i][j]])
				return false;
			visited[grid[i][j]] = true;
		}
	return true;
}

bool CheckRow(int i) {
	vector<bool> visited(10, false);
	for (int j = 0; j < n; j++){
		if (visited[grid[i][j]])
			return false;
		visited[grid[i][j]] = true;
	}
	return true;
}

bool CheckCol(int j) {
	vector<bool> visited(10, false);
	for (int i = 0; i < n; i++) {
		if (visited[grid[i][j]])
			return false;
		visited[grid[i][j]] = true;
	}
	return true;
}

bool Check() {
	for (int i = 0; i < n; i += 3)
		for (int j = 0; j < n; j += 3)
			if (CheckSquare(i, j) == false)
				return false;
	for (int i = 0; i < n; i++)
		if (CheckRow(i) == false)
			return false;
	for (int j = 0; j < n; j++)
		if (CheckCol(j) == false)
			return false;
	return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		grid.assign(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> grid[i][j];

		cout << '#' << test_case << ' ' << Check() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}