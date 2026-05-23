#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		arr.assign(n, 0);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr.begin(), arr.end());

		cout << '#' << test_case << ' ' << arr[0] * arr[n-1] << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}