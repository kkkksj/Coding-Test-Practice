#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	vector<int> cnts;
	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		cnts.assign(50001, 0);
		while (n--) {
			int a, b;
			cin >> a >> b;
			for (int i = a; i <= b; i++)
				cnts[i]++;
		}

		cin >> n;
		int c;
		cout << '#' << test_case << ' ';
		while (n--) {
			cin >> c;
			cout << cnts[c] << ' ';
		}

		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}