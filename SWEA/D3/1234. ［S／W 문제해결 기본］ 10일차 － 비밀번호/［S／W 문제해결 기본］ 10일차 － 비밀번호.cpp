#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	deque<char> q;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		string num;

		cin >> n >> num;

		for (char c : num) {
			if (!q.empty() && (c == q.back()))
				q.pop_back();
			else
				q.push_back(c);
		}

		cout << '#' << test_case << ' ';
		while (!q.empty()) {
			cout << q.front();
			q.pop_front();
		}
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}