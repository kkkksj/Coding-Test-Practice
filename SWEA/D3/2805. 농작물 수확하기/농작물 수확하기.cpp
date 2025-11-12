#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		string num;
		int cnt = 1;
		int ans = 0;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			cin >> num;
			for (int d = 0; d < cnt; d++) {
				ans += num[(n / 2) - d] - '0';
				if (d != 0)
					ans += num[(n / 2) + d] - '0';
			}
			if (flag) {
				cnt++;
				if (cnt == (n / 2) + 1)
					flag = false;
			}
			else
				cnt--;
		}

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}