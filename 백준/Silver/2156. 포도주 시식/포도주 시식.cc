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

    vector<int> w(n);
    vector<int> dp(n);
    for(int i=0; i<n; i++){
        cin >> w[i];
        if(i == 0)
            dp[i] = w[i];
        else if(i == 1)
            dp[i] = dp[i-1] + w[i]; 
        else if(i==2)
            dp[i] = max({dp[i-1], dp[i-2]+w[i], w[i-1]+w[i]});
        else
            dp[i] = max({dp[i-1], dp[i-2]+w[i], dp[i-3]+w[i-1]+w[i]});
    }

    cout << dp[n-1] << '\n';
}