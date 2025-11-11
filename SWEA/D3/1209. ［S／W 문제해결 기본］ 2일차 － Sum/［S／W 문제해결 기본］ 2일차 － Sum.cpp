#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;
	int n = 100;
	vector<int> colsum;

	for (test_case = 1; test_case <= T; ++test_case) {
		int tmp;
		cin >> tmp;

		int max_rowsum = 0;
		colsum.assign(100, 0);
		int rcross = 0;
		int lcross = 0;

		int num;
		for (int i = 0; i < n; i++) {
			int rowsum = 0;
			for (int j = 0; j < n; j++) {
				cin >> num;
				rowsum += num;
				colsum[j] += num;
				if (i == j)
					rcross += num;
				if (i == n - 1 - j)
					lcross += num;
			}
			max_rowsum = max(max_rowsum, rowsum);
		}
		int ans = 0;
		ans = *max_element(colsum.begin(), colsum.end());
		ans = max(ans, max_rowsum);
		ans = max(ans, rcross);
		ans = max(ans, lcross);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}