#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<vector<int>> arrs;
vector<long long> sum_arr;

int LowerBound(long long num) {
	int i = 0, j = sum_arr.size();
	int m;

	while (i < j) {
		m = (i + j) / 2;
		if (sum_arr[m] < num)
			i = m + 1;
		else
			j = m;
	}
	return i;
}

int UpperBound(long long num) {
	int i = 0, j = sum_arr.size();
	int m;

	while (i < j) {
		m = (i + j) / 2;
		if (sum_arr[m] <= num)
			i = m + 1;
		else
			j = m;
	}
	return i;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	arrs.assign(4, vector<int>(n));

	for (int i = 0; i < n; i++) 
		cin >> arrs[0][i] >> arrs[1][i] >> arrs[2][i] >> arrs[3][i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum_arr.push_back(arrs[2][i] + arrs[3][j]);

	sort(sum_arr.begin(), sum_arr.end());

	long long ans = 0;
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			long long target = (long long)arrs[0][i] + arrs[1][j];
			int ans_i = LowerBound(-target);
			int ans_j = UpperBound(-target);
			ans += (ans_j - ans_i);
		}
	cout << ans << '\n';
}