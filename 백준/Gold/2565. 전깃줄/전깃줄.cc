#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int> (2));
    for(int i=0; i<n; i++)
        cin >> arr[i][0] >> arr[i][1];
    
    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);
    int maxl = 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++)
            if(arr[j][1] < arr[i][1])
                dp[i] = max(dp[i], dp[j]+1);
        
        maxl = max(maxl, dp[i]);
    }

    cout << n-maxl << '\n';
}