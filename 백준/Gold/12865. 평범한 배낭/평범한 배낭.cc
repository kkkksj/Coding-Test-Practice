#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> kgs(n+1, 0);  
    vector<int> ws(n+1, 0);  
    for(int i=1; i<n+1; i++){
        int kg, w;
        cin >> kg >> w;
        kgs[i] = kg;
        ws[i] = w;
    }

    vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
    for(int i=1; i<n+1; i++)
        for(int j=1; j<k+1; j++){
            if(j >= kgs[i])
                dp[i][j] = max(dp[i-1][j], ws[i] + dp[i-1][j-kgs[i]]);
            else
                dp[i][j] = dp[i-1][j];
        }

    cout << dp[n][k] << '\n';
}