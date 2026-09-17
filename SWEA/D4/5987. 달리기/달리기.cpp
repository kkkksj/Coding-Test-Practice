#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define MAXN 16
#define MAXMASK (1 << MAXN)

using namespace std;

int n, m;
int pre[MAXN];
long long dp[MAXMASK];

long long GetCount() {
	int maxmask = 1 << n;

	for(int i=0; i<maxmask; i++)
		dp[i] = 0;

	dp[0] = 1;

	for(int mask=0; mask<maxmask; mask++) {
		if (dp[mask] == 0)
			continue;

		for(int i=0; i<n; i++) {
			int bit = 1 << i;

			if (mask & bit)
				continue;

			if ((pre[i] & mask) != pre[i])
				continue;

			dp[mask | bit] += dp[mask];
		}
	}

	return dp[maxmask - 1];
}

int main(int argc, char** argv)
{
	int t;
	cin >> t;

	for(int test_case=1; test_case<=t; test_case++) {
		cin >> n >> m;

		for(int i=0; i<n; i++)
			pre[i] = 0;

		for(int i=0; i<m; i++) {
			int x, y;
			cin >> x >> y;

			x--;
			y--;

			pre[y] |= (1 << x);
		}

		long long answer = GetCount();

		cout << "#" << test_case << " " << answer << '\n';
	}

	return 0;
}