#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> arr1(n+1);
	vector<int> arr2(n+1);
	int sum = 0;
	for (int i = 1; i < n+1; i++)
		cin >> arr1[i];
	for (int i = 1; i < n+1; i++) {
		cin >> arr2[i];
		sum += arr2[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(10001, 0));
	for (int i = 1; i < n+1; i++)
		for (int j = 0; j < sum+1; j++) {
			if (j - arr2[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - arr2[i]] + arr1[i]);

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}

	for (int i = 0; i <= sum; i++)
		if (dp[n][i] >= m) {
			cout << i << '\n';
			break;
		}
}