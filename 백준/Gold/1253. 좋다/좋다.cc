#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[2001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int target = arr[i];
        int l = 0, r = n - 1;

        while (l < r) {
            if (l == i) { l++; continue; }
            if (r == i) { r--; continue; }

            int sum = arr[l] + arr[r];

            if (sum == target) {
                ans++;
                break;
            }
            else if (sum < target) l++;
            else r--;
        }
    }

    cout << ans;
}