#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		vector<long long> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		long long profit = 0;
		long long max_pr = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] > max_pr)
				max_pr = arr[i];
			else
				profit += max_pr - arr[i];
		}

		cout << '#' << test_case << ' ' << profit << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}