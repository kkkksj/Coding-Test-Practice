#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int tc;
		cin >> tc;

		int a, b;
		cin >> a >> b;

		int ans = 1;
		while (b--)
			ans *= a;

		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}