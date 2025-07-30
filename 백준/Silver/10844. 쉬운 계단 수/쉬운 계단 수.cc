#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<vector<long long>> dp(n+1, vector<long long>(10));
    for(int i=1; i<10; i++)
        dp[1][i] = 1;
    for(int i=2; i<n+1; i++){
        for(int j=0; j<10; j++){
            if(j==0)
                dp[i][j] = dp[i-1][1] % MOD;
            else if(j<9)
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
            else
                dp[i][j] = dp[i-1][8] % MOD;
        }
    }
    
    long long ans = 0;
    for(long long a : dp[n])
        ans += a;
    
    cout << ans % MOD << '\n';
}