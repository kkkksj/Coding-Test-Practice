#include<iostream>

using namespace std;

int Cal(int a, int b, int n) {
	int ret = 0;
	int tmp = b;
	while (a <= n) {
		ret++;
		a += b;
		b = a;
		a = tmp;
		tmp = b;
	}
	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int a, b, n;
		cin >> a >> b >> n;

		int ans;
		if (a < b)
			ans = Cal(a, b, n);
		else
			ans = Cal(b, a, n);

		cout << ans-1 << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}