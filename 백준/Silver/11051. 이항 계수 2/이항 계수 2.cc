#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    //파스칼 공식 이용
    // C(n, k) = C(n-1, k-1) + C(n-1, k)
    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for(int i=0; i<n+1; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j=1; j<i; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }
    cout << dp[n][k] << '\n';
}