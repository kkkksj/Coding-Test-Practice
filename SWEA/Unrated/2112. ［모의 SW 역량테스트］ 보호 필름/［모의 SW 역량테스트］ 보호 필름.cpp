#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int d, w, k;
int film[13][20];
int aorb[13]; // -1: 원래 상태, 0: A(0), 1: B(1)

bool IsPass() {
    for (int j = 0; j < w; j++) {
        int cnt = 1;
        bool column_pass = false;

        if (k == 1) column_pass = true;
        else {
            int pre = (aorb[0] != -1) ? aorb[0] : film[0][j];
            for (int i = 1; i < d; i++) {
                int now = (aorb[i] != -1) ? aorb[i] : film[i][j];
                if (pre == now) cnt++;
                else {
                    pre = now;
                    cnt = 1;
                }
                if (cnt >= k) {
                    column_pass = true;
                    break;
                }
            }
        }
        if (!column_pass) return false;
    }
    return true;
}

bool AorB(const vector<int>& target_rows, int idx) {
    if (idx == target_rows.size()) {
        return IsPass();
    }

    int row_idx = target_rows[idx];

    aorb[row_idx] = 0;
    if (AorB(target_rows, idx + 1)) return true;

    aorb[row_idx] = 1;
    if (AorB(target_rows, idx + 1)) return true;

    aorb[row_idx] = -1;
    return false;
}

bool Back(int start, int cnt, int limit, vector<int>& selected) {
    if (cnt == limit) {
        return AorB(selected, 0);
    }

    for (int i = start; i < d; i++) {
        selected.push_back(i);
        if (Back(i + 1, cnt + 1, limit, selected)) 
            return true;
        selected.pop_back(); 
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> d >> w >> k;
        for (int i = 0; i < d; i++) {
            aorb[i] = -1; // 초기화
            for (int j = 0; j < w; j++) 
                cin >> film[i][j];
        }

        int ans = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> selected;
            if (Back(0, 0, i, selected)) {
                ans = i;
                break;
            }
        }
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}