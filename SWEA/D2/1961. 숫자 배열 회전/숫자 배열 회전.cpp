#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<char>> grid;
vector<string> rot90;
vector<string> rot180;
vector<string> rot270;

void Rot90() {
	for(int j = 0; j < n; j++)
		for (int i = n - 1; i >= 0; i--) 
			rot90[j] += grid[i][j];
}

void Rot180() {
	for (int i = n - 1; i >= 0; i--)
		for (int j = n - 1; j >= 0; j--)
			rot180[(n - 1) - i] += grid[i][j];
}

void Rot270() {
	for (int j = n - 1; j >= 0; j--)
		for (int i = 0; i < n; i++)
			rot270[(n - 1) - j] += grid[i][j];
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		grid.assign(n, vector<char>(n));
		rot90.assign(n, "");
		rot180.assign(n, "");
		rot270.assign(n, "");

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> grid[i][j];
		Rot90();
		Rot180();
		Rot270();

		cout << '#' << test_case << '\n';
		for (int i = 0; i < n; i++) {
			cout << rot90[i] << ' ' << rot180[i] << ' ' << rot270[i] << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}