#include<iostream>
#include<unordered_map>

using namespace std;

#define MOD 1000000007

unordered_map<long long, long long> m;

long long fibo(long long num) {
	if (m[num])
		return m[num];

	long long ret;
	if (num % 2 == 0)
		ret = (fibo(num / 2) * (fibo(num / 2 + 1) + fibo(num / 2 - 1))) % MOD;
	else
		ret = ((fibo((num + 1) / 2) * fibo((num + 1) / 2)) % MOD) + ((fibo((num - 1) / 2) * fibo((num - 1) / 2)) % MOD) % MOD;
	return m[num] = ret % MOD;
}

int main(int argc, char** argv)
{
	long long n;
	cin >> n;
	m[0] = 0;
	m[1] = 1;
	m[2] = 1;

	cout << fibo(n);
}	