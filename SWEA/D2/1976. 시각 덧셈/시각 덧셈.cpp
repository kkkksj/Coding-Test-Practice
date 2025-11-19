#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int h1, m1, h2, m2;
		cin >> h1 >> m1 >> h2 >> m2;

		int ansh, ansm;
		ansm = (m1 + m2) % 60;
		ansh = h1 + h2 + (m1 + m2) / 60;
		if (ansh > 12)
			ansh -= 12;

		cout << '#' << test_case << ' ' << ansh << ' ' << ansm << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}