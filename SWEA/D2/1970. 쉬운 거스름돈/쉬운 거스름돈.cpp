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

		vector<int> list = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
		vector<int> ans = { 0, 0, 0, 0, 0, 0, 0, 0 };

		for (int i = 0; i < 8; i++) {
			int a = num / list[i];
			num -= list[i] * a;
			ans[i] = a;
		}

		cout << '#' << test_case << '\n';
		for (int a : ans)
			cout << a << ' ';
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}