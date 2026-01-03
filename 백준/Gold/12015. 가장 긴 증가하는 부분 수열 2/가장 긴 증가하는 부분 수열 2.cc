#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int LowerBound(vector<int>& vec, int num) {
	int i = 0, j = vec.size() - 1;

	while (i <= j) {
		int mid = (i + j) / 2;
		if (vec[mid] < num)
			i = mid + 1;
		else
			j = mid - 1;
	}

	return j + 1;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr (n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> vec;
	for (int num : arr) {
		if (vec.empty() || vec.back() < num)
			vec.push_back(num);
		else {
			int idx = LowerBound(vec, num);
			vec[idx] = num;
		}
	}
	
	cout << vec.size() << '\n';
}