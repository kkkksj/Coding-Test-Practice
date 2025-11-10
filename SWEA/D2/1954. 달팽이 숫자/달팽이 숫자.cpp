#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> grid;
vector<int> j_list = { 1, 0, -1, 0 };
vector<int> i_list = { 0, 1, 0, -1 };

void Write(int n) {
	int now_i = 0, now_j = 0;
	int d = 0;
	for (int i = 1; i < n * n + 1; i++) {
		grid[now_i][now_j] = i;
		if (now_i + i_list[d] < 0 || now_i + i_list[d] >= n || now_j + j_list[d] < 0 || now_j + j_list[d] >= n || grid[now_i + i_list[d]][now_j + j_list[d]] != 0)
			d = (d + 1) % 4;
		now_i += i_list[d];
		now_j += j_list[d];
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	vector<int> d_list = { -2, -1, 1, 2 };
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		grid.assign(n, vector<int>(n, 0));
		
		Write(n);

		cout << '#' << test_case << '\n';
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				cout << grid[i][j] << ' ';
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}