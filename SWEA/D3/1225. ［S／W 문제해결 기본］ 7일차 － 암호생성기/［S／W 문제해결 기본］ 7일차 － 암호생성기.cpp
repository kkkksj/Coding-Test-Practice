#include<iostream>
#include<deque>

using namespace std;

deque<int> dq;

void Find() {
	int cnt = 1;
	while (true) {
		if (cnt > 5)
			cnt = 1;
		int num = dq.front();
		dq.pop_front();

		if (num - cnt <= 0) {
			dq.push_back(0);
			return;
		}

		dq.push_back(num - cnt);

		cnt++;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int tc;
		cin >> tc;

		int num;
		for (int i = 0; i < 8; i++) {
			cin >> num;
			dq.push_back(num);
		}

		Find();

		cout << '#' << test_case << ' ';
		while (!dq.empty()) {
			cout << dq.front() << ' ';
			dq.pop_front();
		}
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}