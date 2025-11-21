#include<iostream>

using namespace std;

int n, r;
int MOD = 1234567891;

long long factorial(int n) {
	long long result = 1;
	for (int i = 2; i <= n; i++) {
		result = (result * i) % MOD;
	}
	return result;
}

long long power(long long a, int b) {
	long long result = 1;

	while (b > 0) {
		if (b % 2 == 1) {
			result = (result * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}

	return result;
}

long long modInverse(long long a) {
	return power(a, MOD - 2);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> r;
		
		long long a = factorial(n);
		long long b = modInverse(factorial(r));
		long long c = modInverse(factorial(n - r));

		long long ans = a;
		ans = (ans * b) % MOD;
		ans = (ans * c) % MOD;

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}