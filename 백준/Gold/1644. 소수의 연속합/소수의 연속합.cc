#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int Find(vector<int>& sumarr, int k) {
	int n = sumarr.size();
	int ans = 0;
	int i = 0, j = 1;
	while (j < n) {
		if (sumarr[j] - sumarr[i] == k) {
			ans++;
			i++;
			j++;
		}
		else if (sumarr[j] - sumarr[i] < k)
			j++;
		else
			i++;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n + 1, true);
	arr[1] = false;
	for (int i = 2; i < sqrt(n + 1); i++) {
		if (arr[i] == false)
			continue;
		for (int j = i + i; j < n + 1; j += i)
			arr[j] = false;
	}

	vector<int> sumarr;
	sumarr.push_back(0);
	int pre = 0;
	for (int i = 2; i < n + 1; i++)
		if (arr[i]) {
			sumarr.push_back(pre + i);
			pre += i;
		}

	cout << Find(sumarr, n) << '\n';
}