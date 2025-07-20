#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr (n);
    vector<int> dp (n);
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            if(arr[i] > arr[j])
                dp[i] = max(dp[j]+arr[i], dp[i]);
        ans = max(ans, dp[i]);
    }
                 
    cout << ans << '\n';
}