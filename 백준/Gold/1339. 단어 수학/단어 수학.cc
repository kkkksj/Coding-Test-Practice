#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(26);
	
	for (int i = 0; i < n; i++) {
		string text;
		cin >> text;

		int cal = 1;
		for (int j = text.length() - 1; j > -1; j--) {
			arr[text[j] - 'A'] += cal;
			cal *= 10;
		}
	}

	sort(arr.begin(), arr.end(), greater<int>());
	int num = 9;
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0)
			break;
		ans += (arr[i] * num--);
	}
	cout << ans << '\n';
}