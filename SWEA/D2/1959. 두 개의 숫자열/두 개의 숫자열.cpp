#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int n, m;
vector<int> arr1;
vector<int> arr2;

int Search(int a, int b, vector<int> &arr1, vector<int>& arr2) {
	int ret = INT_MIN;
	for (int i = 0; i < b - a + 1; i++) {
		int cal = 0;
		for (int j = 0; j < a; j++)
			cal += (arr1[j] * arr2[i + j]);
		ret = max(ret, cal);
	}

	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> m;
		arr1.assign(n, 0);
		arr2.assign(m, 0);

		for (int i = 0; i < n; i++)
			cin >> arr1[i];
		for (int i = 0; i < m; i++)
			cin >> arr2[i];

		int ans = 0;
		if (n <= m)
			ans = Search(n, m, arr1, arr2);
		else
			ans = Search(m, n, arr2, arr1);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}