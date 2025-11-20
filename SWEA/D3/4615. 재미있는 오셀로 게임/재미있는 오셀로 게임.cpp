#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int n, m;
vector<vector<int>> arr;
vector<int> i_list = { -1, -1, -1, 0, 1, 1, 1, 0 };
vector<int> j_list = { -1, 0, 1, 1, 1, 0, -1, -1 };
vector<int> opposite = { 4, 5, 6, 7, 0, 1, 2, 3 };
vector<int> opposite_color = { 0, 2, 1 };

void Search(int i, int j, int d, int color) {
	int now_i = i, now_j = j;
	while (true) {
		now_i += i_list[d];
		now_j += j_list[d];
		
		if (now_i < 1 || now_i >= n + 1 || now_j < 1 || now_j >= n + 1 || arr[now_i][now_j] == 0)
			return;
		if (arr[now_i][now_j] == color)
			break;
	}

	int opp_d = opposite[d];
	while(true){
		now_i += i_list[opp_d];
		now_j += j_list[opp_d];

		arr[now_i][now_j] = color;
		if (now_i == i && now_j == j)
			return;
	}
	return;
}

void Put(int i, int j, int color) {
	arr[i][j] = color;
	for (int d = 0; d < 8; d++) {
		int next_i = i + i_list[d];
		int next_j = j + j_list[d];
		if (next_i < 1 || next_i >= n+1 || next_j < 1 || next_j >= n+1 || arr[next_i][next_j] == 0)
			continue;
		if (arr[next_i][next_j] == opposite_color[color])
			Search(next_i, next_j, d, color);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> m;
		arr.assign(n + 1, vector<int>(n + 1, 0));

		arr[n / 2][n / 2] = 2;
		arr[n / 2][n / 2 + 1] = 1;
		arr[n / 2 + 1][n / 2] = 1;
		arr[n / 2 + 1][n / 2 + 1] = 2;

		int i, j, color;
		while (m--) {
			cin >> i >> j >> color;
			Put(i, j, color);
		}

		int ans_b = 0, ans_w = 0;
		for(int i=1; i<n+1; i++)
			for (int j = 1; j < n+1; j++) {
				if (arr[i][j] == 1)	ans_b++;
				else if (arr[i][j] == 2) ans_w++;
			}

		cout << '#' << test_case << ' ' << ans_b << ' ' << ans_w << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}