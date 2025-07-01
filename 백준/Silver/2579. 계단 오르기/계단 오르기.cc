#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> stairs(n+1);
    for(int i=1; i<n+1; i++)
        cin >> stairs[i];
    
    vector<int> dp(n+1);
    dp[1] = stairs[1];
    if(n > 1)
        dp[2] = stairs[1] + stairs[2];
    for(int i=3; i<n+1; i++)
        dp[i] = max(dp[i-2] + stairs[i], dp[i-3]+stairs[i-1]+stairs[i]);
    

    cout << dp[n] << '\n';
}