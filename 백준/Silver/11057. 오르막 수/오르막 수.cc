#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> dp(n+1, vector<int> (10, 1));
    dp[1] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    if(n>1){
        dp[2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for(int i=3; i<n+1; i++)
            for(int j=1; j<10; j++)
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%10007;
    }
    
    int ans = 0;
    for(int tmp : dp[n])
        ans += tmp;
    cout << ans%10007 << '\n';
}