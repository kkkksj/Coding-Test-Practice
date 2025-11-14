#include<iostream>
#include<vector>

using namespace std;

int FindMax(vector<int>& a, int n, vector<int>& b, int m) {
	int ret = 0;
	for (int i = 0; i <= m - n; i++) {
		int sum = 0;
		for (int j = i; j < i+n; j++)
			sum += (a[j-i] * b[j]);
		ret = max(ret, sum);
	}

	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n, 0);
		vector<int> b(m, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int j = 0; j < m; j++)
			cin >> b[j];

		int ans;
		if (n < m)
			ans = FindMax(a, n, b, m);
		else
			ans = FindMax(b, m, a, n);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}