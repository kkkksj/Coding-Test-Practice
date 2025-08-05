#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n+1, 0);
    for(int i=1; i<n+1; i++)
        cin >> arr[i];

    vector<int> dp(n+1, 0);
    for(int i=1; i<n+1; i++){
        dp[i] = arr[i];
        for(int j=1; j<i+1; j++)
            dp[i] = max(dp[i], dp[j]+dp[i-j]);
    }

    cout << dp[n] << '\n';
}