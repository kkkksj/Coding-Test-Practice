#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> cnt(m, 0);
    long long sum = 0;
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        sum += num;

        int remainder = sum % m;
        if (remainder == 0) answer++;

        cnt[remainder]++;
    }

    for (int i = 0; i < m; i++) {
        if (cnt[i] >= 2) {
            answer += (cnt[i] * (cnt[i] - 1)) / 2;
        }
    }

    cout << answer << "\n";

    return 0;
}