#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n, k;
		cin >> n >> k;

		vector<vector<int>> puzzle(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> puzzle[i][j];

		int ans = 0;
		for (int d = 0; d < n; d++) {
			int cnt_r = 0;
			int cnt_c = 0;
			for(int i=0; i<n; i++) {
				if (puzzle[i][d] == 0) {
					if (cnt_r == k) 
						ans++;
					cnt_r = 0;
				}
				else
					cnt_r++;
				if (puzzle[d][i] == 0) {
					if (cnt_c == k)
						ans++;
					cnt_c = 0;
				}
				else
					cnt_c++;
			}
			if (cnt_r == k)
				ans++;
			if (cnt_c == k)
				ans++;
		}
		
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}