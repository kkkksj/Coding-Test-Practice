#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int> (n, 0));
    int num;
    cin >> dp[0][0];
    int ans = 0;
    for(int i=2; i<n+1; i++){
        for(int k=0; k<i; k++){
            cin >> num;
            if(k == 0)
                dp[i-1][k] = dp[i-2][k] + num;
            else if (k<i-1)
                dp[i-1][k] = max(dp[i-2][k-1], dp[i-2][k]) + num;
            else
                dp[i-1][k] = dp[i-2][k-1] + num;
            if(i == n)
                ans = max(ans, dp[i-1][k]);
        }
    }

    if(n==1)
        cout << dp[0][0] << '\n';
    else
        cout << ans << '\n';
}   