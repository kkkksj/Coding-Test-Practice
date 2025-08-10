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
    
    vector<int> dp(n+1, 0);
    vector<string> before(n+1, "");
    dp[1] = 1;
    before[1] = "1";
    int prev;
    for(int i=2; i<n+1; i++){
        dp[i] = dp[i-1] + 1;
        prev = i-1;
        if(i%3 == 0)
            if(dp[i/3] + 1 < dp[i]){
                dp[i] = dp[i/3] + 1;
                prev = i/3;
            }
        if(i%2 == 0)
            if(dp[i/2] + 1 < dp[i]){
                dp[i] = dp[i/2] + 1;
                prev = i/2;
            }
        before[i] = to_string(i) + " " + before[prev];
    }

    cout << dp[n]-1 << '\n' << before[n];
}