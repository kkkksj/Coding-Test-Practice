#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		int ans_num = 100001;
		int ans_cnt = 0;
		int num;

		while (n--) {
			cin >> num;
			if (abs(num) < ans_num) {
				ans_cnt = 1;
				ans_num = abs(num);
			}
			else if (abs(num) == ans_num)
				ans_cnt++;
		}

		cout << '#' << test_case << ' ' << ans_num << ' ' << ans_cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}