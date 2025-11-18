#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		char c;
		int num;
		string ans = "";
		cout << '#' << test_case << '\n';
		while (n--) {
			cin >> c >> num;
			for (int i = 0; i < num; i++) {
				if (ans.size() == 10) {
					cout << ans << '\n';
					ans = "";
				}
				ans += c;
			}
		}
		cout << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}