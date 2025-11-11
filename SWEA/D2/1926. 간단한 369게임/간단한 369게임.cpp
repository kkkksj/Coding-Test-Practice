#include<iostream>
#include<string>

using namespace std;

string Check(string num) {
	string ret = "";
	for (char c : num) 
		if (c == '3' || c == '6' || c == '9')
			ret += "-";
	if (ret == "")
		return num;
	return ret;
}

int main(int argc, char** argv)
{
	/*int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {

	}*/

	int n;
	cin >> n;

	for (int i = 1; i < n + 1; i++) 
		cout << Check(to_string(i)) << ' ';
	cout << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}