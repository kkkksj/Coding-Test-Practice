#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> arr(n, pair<int, int>());
	vector<vector<pair<int, int>>> dp_arr(n, vector<pair<int, int>>(n));
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
		dp_arr[i][i] = arr[i];
	}

	for(int i=1; i<n; i++)
		for (int j = 0; j + i < n; j++) {
			int l = j + i;
			dp[j][l] = INT_MAX;
			for(int m=j; m<l; m++) {
				int cal = dp_arr[j][m].first * dp_arr[j][m].second * dp_arr[m + 1][l].second;
				dp[j][l] = min(dp[j][l], dp[j][m] + dp[m + 1][l] + cal);
			}
			dp_arr[j][l].first = arr[j].first;
			dp_arr[j][l].second = arr[l].second;
		}

	cout << dp[0][n - 1];
}