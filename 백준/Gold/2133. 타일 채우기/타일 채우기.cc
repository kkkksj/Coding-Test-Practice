#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n+1, 0);

    if(n%2 == 1){
        cout << 0 << '\n';
        return 0;
    }
    
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4; i<n+1; i++){
        dp[i] = dp[i-2] * dp[2];
        for(int j=i-4; j>=0; j-=2)
            dp[i] = dp[i] + (dp[j]*2);
    }

    cout << dp[n] << '\n';
}