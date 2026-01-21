#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> cnt(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		double max = -INT_MAX;
		for (int j = i + 1; j < n; j++) {
			double num = (double)(arr[j] - arr[i]) / (j - i);
			if (num > max) {
				cnt[i]++;
				cnt[j]++;
				max = num;
			}
		}
	}
	int ans = 0;
	for (int a : cnt)
		ans = max(ans, a);
	cout << ans << '\n';
}