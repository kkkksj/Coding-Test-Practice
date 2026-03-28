#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (ans.size() == 0 || ans[ans.size() - 1] < arr[i])
			ans.push_back(arr[i]);
		else {
			int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			ans[pos] = arr[i];
		}
	}

	cout << ans.size() << '\n';
}