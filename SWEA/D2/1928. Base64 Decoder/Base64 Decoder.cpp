#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

string rule = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string ToBinary(int num) {
	string ret = "";
	for (int i = 5; i >= 0; i--) {
		if (pow(2, i) <= num) {
			num -= pow(2, i);
			ret += '1';
		}
		else
			ret += '0';
	}

	return ret;
}

char ToDecimal(string bit) {
	int ret = 0;
	for (int i = 0; i < 8; i++) 
		if (bit[7-i] == '1')
			ret += pow(2, i);

	return ret;
}

int FindIdx(char c) {
	for (int i = 0; i < 64; i++)
		if (rule[i] == c)
			return i;
	return -1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string text;
		cin >> text;

		string tobinary = "";
		for (char c : text) 
			tobinary += ToBinary(FindIdx(c));

		string eightbit = "";
		string ans = "";
		for(char c : tobinary){
			eightbit += c;
			if (eightbit.size() == 8) {
				ans += ToDecimal(eightbit);
				eightbit = "";
			}
		}
				
		cout << '#' << test_case << ' ';
		for (char c : ans)
			cout << c;
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}