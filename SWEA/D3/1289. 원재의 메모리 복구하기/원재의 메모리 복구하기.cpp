#include<iostream>
#include<vector>

using namespace std;

int Find(string& num) {
	int n = num.size();
	char now = num[0];
	int ret = (now=='1') ? 1 : 0;

	for (char c : num) {
		if (c != now) {
			ret++;
			now = (now == '0') ? '1' : '0';
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string num;
		cin >> num;

		int ans = Find(num);
		
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}