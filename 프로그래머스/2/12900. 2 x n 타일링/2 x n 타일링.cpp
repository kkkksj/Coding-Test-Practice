#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int n) {
    vector<long long> dp(n + 1, 0);

    dp[1] = 1;

    if (n >= 2)
        dp[2] = 2;

    for (int i = 3; i <= n; i++) 
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    return dp[n];
}