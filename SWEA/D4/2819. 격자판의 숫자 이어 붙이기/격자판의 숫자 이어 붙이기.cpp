#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

vector<vector<char>> arr;
unordered_set<string> set;
vector<int> i_list = { -1, 0, 1, 0 };
vector<int> j_list = { 0, -1, 0, 1 };

void DFS(int i, int j, string num) {
	if (num.size() == 7) {
		set.insert(num);
		return;
	}
	for (int d = 0; d < 4; d++) {
		int next_i = i + i_list[d];
		int next_j = j + j_list[d];

		if (next_i < 0 || next_i >= 4 || next_j < 0 || next_j >= 4)
			continue;
		
		DFS(next_i, next_j, num + arr[next_i][next_j]);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		arr.assign(4, vector<char>(4));
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> arr[i][j];

		set.clear();
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				DFS(i, j, "");

		int ans = set.size();

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}