#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n+1);
    for(int i=1; i<n+1; i++)
        cin >> arr[i];

    int m;
    cin >> m;

    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for(int i=1; i<n+1; i++){
        dp[i][i] = 1;
        if(i!=1 && arr[i-1]==arr[i])
            dp[i-1][i] = 1;    
    }

    for(int i=2; i<n; i++)
        for(int j=1; i+j<n+1; j++)
            if(arr[j]==arr[i+j] && dp[j+1][i+j-1]==1)
                dp[j][i+j] = 1;

    while(m--){
        int i, j;
        cin >> i >> j;

        if(dp[i][j]==1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}