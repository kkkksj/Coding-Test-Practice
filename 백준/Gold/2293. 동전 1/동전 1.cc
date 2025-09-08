#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> worth (n+1);
    for(int i=1; i<n+1; i++)
        cin >> worth[i];
    
    vector<int> dp(k+1);
    dp[0] = 1;
    for(int i=1; i<n+1; i++)
        for(int j=worth[i]; j<k+1; j++)
            dp[j] += dp[j - worth[i]];
        
    cout << dp[k] << '\n';
}