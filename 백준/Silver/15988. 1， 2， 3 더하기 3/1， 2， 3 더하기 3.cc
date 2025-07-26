#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
#define MOD 1000000009
#define MAX 1000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<long long> dp (MAX+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<MAX+1; i++)
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]) % MOD;

    int t;
    cin >> t;
    
    int num;
    for(int i=0; i<t; i++){
        cin >> num;
        cout << dp[num] % MOD << '\n';
    }
}