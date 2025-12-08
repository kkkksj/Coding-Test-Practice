#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int k;
vector<int> arr;
vector<vector<int>> dp_arr;
vector<vector<int>> dp;

int main()
{
	int T;
	cin >> T;

	while (T--) {
		cin >> k;
		arr.assign(k, 0);
		dp_arr.assign(k, vector<int>(k));

		for (int i = 0; i < k; i++) {
			cin >> arr[i];
			dp_arr[i][i] = arr[i];
		}

		for (int i = 1; i < k; i++) {      
			for (int j = 0; j + i < k; j++) {  
				int l = j + i;                 
				dp_arr[j][l] = dp_arr[j][l - 1] + arr[l];
			}
		}

		dp.assign(k, vector<int>(k));
		for(int i=1; i<k; i++)
			for (int j = 0; i + j < k; j++) {
				int l = i + j;
				dp[j][l] = INT_MAX;
				for (int m = j; m < l; m++) {
					int cal = dp[j][m] + dp_arr[j][l] + dp[m + 1][l];
					dp[j][l] = min(dp[j][l], cal);
				}
			}

		cout << dp[0][k - 1] << '\n';
	}
}