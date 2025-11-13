#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;

		int a = p * w;
		int b = w <= r ? q : q + (w - r) * s;

		int ans = min(a, b);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}