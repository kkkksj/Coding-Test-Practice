#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> dp (n+1);
    dp[1] = 1;
    for(int i=2; i<n+1; i++){
        if(i%2 == 0)
            dp[i] = ((dp[i-1] * 2) + 1)%10007;
        else
            dp[i] = ((dp[i-1] * 2) - 1)%10007;
    }

    cout << dp[n] << '\n';
}