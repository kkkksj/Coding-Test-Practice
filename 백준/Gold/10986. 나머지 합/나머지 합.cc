#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<long long> cnt(m, 0);
	long long pre = 0;

	cnt[0] = 1;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		pre = (pre + num) % m;
		cnt[pre]++;
	}

	long long ans = 0;
	for (int i = 0; i < m; i++)
		if (cnt[i] >= 2)
			ans += (cnt[i] * (cnt[i] - 1)) / 2;

	cout << ans << '\n';
}