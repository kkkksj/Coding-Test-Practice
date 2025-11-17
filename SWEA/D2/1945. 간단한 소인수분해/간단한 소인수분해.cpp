#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int num;
		cin >> num;

		vector<int> list = { 2, 3, 5, 7, 11 };
		vector<int> ans = { 0, 0, 0, 0, 0 };

		for (int i = 0; i < 5; i++) {
			while (num % list[i] == 0) {
				ans[i]++;
				num /= list[i];
			}
		}

		cout << '#' << test_case << ' ';
		for (int a : ans)
			cout << a << ' ';
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}