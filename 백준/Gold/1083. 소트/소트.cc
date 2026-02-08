#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int maxn;
	cin >> maxn;

	int idx = 0;
	while (maxn>0 && idx < n) {
		int maxidx = idx;
		for (int i = idx + 1; i < min(n, idx + maxn + 1); i++)
			if (arr[maxidx] < arr[i])
				maxidx = i;
		for (int i = maxidx; i > idx; i--) { // 최대값 앞으로 끌어오기
			swap(arr[i], arr[i - 1]);
			maxn--;
		}
		idx++;
	}
	for (int a : arr)
		cout << a << ' ';
	cout << '\n';
}