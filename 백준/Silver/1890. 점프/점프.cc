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

    vector<vector<int>> board(n, vector<int> (n));
    vector<vector<long long>> dp(n, vector<long long> (n, 0));
    dp[0][0] = 1;
    int num;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> num;
            board[i][j] = num;
            
            if(num == 0)
                continue;
            if(j+num < n)
                dp[i][j+num] += dp[i][j];
            if(i+num < n)
                dp[i+num][j] += dp[i][j];
        }
    
    cout << dp[n-1][n-1] << '\n';
}