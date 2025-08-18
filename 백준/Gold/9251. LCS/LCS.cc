#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    int sz_a = (int)a.size();
    int sz_b = (int)b.size();

    vector<vector<int>> dp(sz_a+1, vector<int> (sz_b+1, 0));

    int ans = 0;
    for(int i=1; i<sz_a+1; i++)
        for(int j=1; j<sz_b+1; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            ans = max(dp[i][j], ans);
        }

    cout << ans << '\n';

}