#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> arr;
vector<vector<string>> ans;

vector<int> i_list = { 0, 1, 0, -1 };
vector<int> j_list = { 1, 0, -1, 0 };

void Rot(int cnt) {
	vector<vector<int>> tmp(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[j][n - 1 - i] = arr[i][j];

	arr = tmp;

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[cnt][i] += (arr[i][j] + '0');
		
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		arr.assign(n, vector<int>(n, 0));
		ans.assign(3, vector<string>(n, ""));
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		for (int cnt = 0; cnt < 3; cnt++)
			Rot(cnt);

		cout << '#' << test_case << '\n';
		for(int i=0; i<n; i++) {
			for (int j = 0; j < 3; j++)
				cout << ans[j][i] << ' ';
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}