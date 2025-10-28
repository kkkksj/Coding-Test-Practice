#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<vector<long long>> dp(k+1, vector<long long> (n+1, 0));
	for(int i=0; i<n+1; i++)
		dp[1][i] = 1;

	for(int i=2; i<k+1; i++)
		for(int j=0; j<n+1; j++){
			for(int l=0; l<j+1; l++)
				dp[i][j] += dp[i-1][l];
			dp[i][j] %= 1000000000;
		}

	cout << dp[k][n] << '\n';
}