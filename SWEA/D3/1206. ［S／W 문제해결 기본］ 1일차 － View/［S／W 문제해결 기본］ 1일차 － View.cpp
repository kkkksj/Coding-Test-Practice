#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	vector<int> d_list = { -2, -1, 1, 2 };
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
	
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int ans = 0;
		for (int i = 2; i < n - 2; i++) {
			int max_h = 0;
			for (int d = 0; d < 4; d++) 
				max_h = max(max_h, arr[i + d_list[d]]);
			if(arr[i] > max_h)
				ans += (arr[i] - max_h);
		}

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}