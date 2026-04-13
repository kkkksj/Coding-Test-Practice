#include <iostream>
#include <vector>

#define min(a, b) a < b ? a : b

using namespace std;

int n, s;
vector <long long> prefix_sum_arr;

int Find() {
	int i = 0, j = 1;;
	int ret = 100000;
	while (j <= n) {
		int ttlsum = prefix_sum_arr[j] - prefix_sum_arr[i];
		if (ttlsum >= s) {
			ret = min(ret, (j-i));
			i++;
		}
		else
			j++;
		if (i == j)
			j++;
	}
	if (ret == 100000)
		return 0;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	prefix_sum_arr.assign(n + 1, 0);

	int num;
	for (int i = 1; i < n + 1; i++) {
		cin >> prefix_sum_arr[i];
		prefix_sum_arr[i] += prefix_sum_arr[i - 1];
	}

	cout << Find() << '\n';
}