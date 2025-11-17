#include<iostream>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int tc;
		string f;
		string text;
		cin >> tc >> f >> text;
		int n = f.size();
		string re = "";
		for (int i = 0; i < n; i++)
			re += '0';
		
		int ans = 0;
		while (true) {
			const char* pos = strstr(text.c_str(), f.c_str());
			if (pos) {
				ans++;
				text.replace(pos - text.c_str(), n, re);
			}
			else
				break;
		}
		
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}