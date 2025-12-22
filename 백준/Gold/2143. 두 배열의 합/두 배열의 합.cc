#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long t;
int n1, n2;
vector<long long> arr1;
vector<long long> arr2;
vector<long long> sum1;
vector<long long> sum2;
long long ans = 0;

int lower(long long num) {
	int i = 0, j = sum2.size();
	int mid;
	while (i < j) {
		mid = (i + j) / 2;
		if (sum2[mid] < num)
			i = mid + 1;
		else
			j = mid;
	}
	return i;
}

int upper(long long num) {
	int i = 0, j = sum2.size();
	int mid;
	while (i < j) {
		mid = (i + j) / 2;
		if (sum2[mid] > num)
			j = mid;
		else
			i = mid + 1;
	}
	return j;
}

int main() {
	cin >> t;

	cin >> n1;
	arr1.assign(n1, 0);
	for (int i = 0; i < n1; i++) 
		cin >> arr1[i];
	cin >> n2;
	arr2.assign(n2, 0);
	for (int i = 0; i < n2; i++) 
		cin >> arr2[i];
	
	for (int i = 0; i < n1; i++) {
		long long sum = 0;
		for (int j = i; j < n1; j++) {
			sum += arr1[j];
			sum1.push_back(sum);
		}
	}

	for (int i = 0; i < n2; i++) {
		long long sum = 0;
		for (int j = i; j < n2; j++) {
			sum += arr2[j];
			sum2.push_back(sum);
		}
	}

	sort(sum2.begin(), sum2.end());

	for (long long sum : sum1) {
		long long rest = t - sum;
		int i = lower(rest);
		int j = upper(rest);
		ans += (j - i);
	}

	cout << ans << '\n';
}