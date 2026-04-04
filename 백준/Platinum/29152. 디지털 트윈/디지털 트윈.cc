#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    int N;
    cin >> N;

    vector<int> rowL(N + 1, -1), rowR(N + 1, -1);

    for (int r = 1; r <= N; r++) {
        string line;
        cin >> line;
        for (int c = 1; c <= N; c++) {
            if (line[c - 1] == '1') {
                if (rowL[r] == -1) {
                    rowL[r] = rowR[r] = c;
                }
                else {
                    rowL[r] = min(rowL[r], c);
                    rowR[r] = max(rowR[r], c);
                }
            }
        }
    }

    vector<int> dp(N + 1, INF);

    for (int c = 1; c <= N; c++) {
        if (rowL[1] == -1 || rowR[1] <= c) {
            dp[c] = c;
        }
    }

    auto transition = [&](int L, int R, bool has) -> vector<int> {
        vector<int> ndp(N + 1, INF);

        if (!has) {
            int minL = INF;
            for (int c = 1; c <= N; c++) {
                if (dp[c] != INF) minL = min(minL, dp[c] - c);
                if (minL != INF) ndp[c] = min(ndp[c], minL + c + 1);
            }
            int minR = INF;
            for (int c = N; c >= 1; c--) {
                if (dp[c] != INF) minR = min(minR, dp[c] + c);
                if (minR != INF) ndp[c] = min(ndp[c], minR - c + 1);
            }
        }
        else {
            {
                int minVal = INF;
                for (int p = 1; p <= L; p++)
                    if (dp[p] != INF) minVal = min(minVal, dp[p] - p);
                for (int c = R; c <= N; c++)
                    if (minVal != INF) ndp[c] = min(ndp[c], minVal + c + 1);
            }
            {
                int minVal = INF;
                for (int p = R; p <= N; p++)
                    if (dp[p] != INF) minVal = min(minVal, dp[p] + p);
                for (int c = 1; c <= L; c++)
                    if (minVal != INF) ndp[c] = min(ndp[c], minVal - c + 1);
            }
        }
        return ndp;
        };

    for (int r = 2; r <= N; r++) {
        bool has = (rowL[r] != -1);
        dp = transition(rowL[r], rowR[r], has);
    }

    int ans = (dp[N] == INF) ? -1 : dp[N];
    cout << ans << "\n";

    return 0;
}