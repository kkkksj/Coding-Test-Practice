#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define MAXN 100
#define MAXP 100

using namespace std;

long long GetMaxCandy(int n, int p) {
	int q = n / p;
	int r = n % p;

	long long answer = 1;

	for(int i=0; i<p-r; i++)
		answer *= q;

	for(int i=0; i<r; i++)
		answer *= (q + 1);

	return answer;
}

int main(int argc, char** argv)
{
	int t;
	cin >> t;

	for(int test_case=1; test_case<=t; test_case++) {
		int n, p;
		cin >> n >> p;

		long long answer = GetMaxCandy(n, p);

		cout << "#" << test_case << " " << answer << '\n';
	}

	return 0;
}