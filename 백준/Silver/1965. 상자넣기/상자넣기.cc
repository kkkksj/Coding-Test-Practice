#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr (n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    vector<int> dp (n, 1);
    int ans = 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++)
            if(arr[j] < arr[i])
                dp[i] = max(dp[j]+1, dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}