#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<long long> arr;
long long min_sum = 3e10;
vector<int> ans = { 0, 0, 0 };

void Search(int a, int b, int c) {
	while (b < c) {
		long long sum = arr[a] + arr[b] + arr[c];
		if (llabs(sum) < min_sum) {
			min_sum = llabs(sum);
			ans[0] = a;	ans[1] = b;	ans[2] = c;
		}
		if (sum < 0)
			b++;
		else
			c--;
	}
}

int main() {
	cin >> n;
	arr.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n - 2; i++)
		Search(i, i + 1, n - 1);

	cout << arr[ans[0]] << ' ' << arr[ans[1]] << ' ' << arr[ans[2]] << '\n';
}