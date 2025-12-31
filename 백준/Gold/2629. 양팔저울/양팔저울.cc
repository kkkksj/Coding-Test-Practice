#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> weights;
vector<vector<bool>> dp;

void Search(int i, int w) {
	if (i > n || dp[i][w])
		return;
	dp[i][w] = true;
	if (i == n) return;
	Search(i + 1, w + weights[i]);
	Search(i + 1, abs(w - weights[i]));
	Search(i + 1, w);
}

int main() {
	cin >> n;
	weights.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> weights[i];

	dp.assign(n+1, vector<bool>(40001, false));
	Search(0, 0);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		if (dp[n][num])
			cout << 'Y' << ' ';
		else
			cout << 'N' << ' ';
	}
}