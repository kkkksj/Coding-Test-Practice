#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    int mod = 9901;
    vector<vector<int>> dp (3, vector<int> (n+1, 0));
    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;

    for(int i=2; i<n+1; i++){
        dp[0][i] = ((dp[0][i-1] + dp[1][i-1])%mod + dp[2][i-1])%mod;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1])%mod;
        dp[2][i] = (dp[0][i-1] + dp[1][i-1])%mod;
    }

    cout << ((dp[0][n]+dp[1][n])%mod+dp[2][n])%mod << '\n';
}