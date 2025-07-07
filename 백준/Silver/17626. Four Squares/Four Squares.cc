#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for(int i=2; i<n+1; i++){
        dp[i] = dp[i-1] + 1;
        for(int j=1; j*j<i+1; j++)
            dp[i] = min(dp[i], dp[i-j*j] + 1);   
            //이 전 값에 1더하는 경우와, 특정한 제곱수 하나를 더하는 경우 중 더 작은 값
        }
    cout << dp[n];
}