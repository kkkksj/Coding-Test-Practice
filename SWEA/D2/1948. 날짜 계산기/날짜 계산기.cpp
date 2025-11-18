#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	vector<int> day = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (test_case = 1; test_case <= T; ++test_case) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;

		int ans = 0;
		int nowm = sm, nowd = sd;
		while (nowm < em) {
			ans += day[nowm] - nowd + 1;
			nowm++;
			nowd = 1;
		}
		ans += ed - nowd + 1;

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}