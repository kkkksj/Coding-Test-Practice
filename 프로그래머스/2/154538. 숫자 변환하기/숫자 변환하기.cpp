#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n) {
    const int INF = 1000000000;

    vector<int> dp(y + 1, INF);
    dp[x] = 0;

    for (int i = x; i <= y; i++) {
        if (dp[i] == INF)
            continue;

        if (i + n <= y)
            dp[i + n] = min(dp[i + n], dp[i] + 1);

        if (i * 2 <= y)
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);

        if (i * 3 <= y)
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }

    if (dp[y] == INF)
        return -1;

    return dp[y];
}