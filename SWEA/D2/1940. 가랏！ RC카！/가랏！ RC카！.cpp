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

		int cmd, ms = 0, tms = 0;
		int ans = 0;
		while (n--) {
			cin >> cmd;
			if (cmd == 1 || cmd == 2) {
				cin >> tms;
				if (cmd == 1)
					ms += tms;
				else
					ms -= tms;
			}

			if (ms < 0)
				ms = 0;
			ans += ms;
		}
		
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}