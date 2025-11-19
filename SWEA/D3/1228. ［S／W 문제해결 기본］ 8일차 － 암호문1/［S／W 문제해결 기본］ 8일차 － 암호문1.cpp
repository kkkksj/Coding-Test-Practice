#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	deque<int> dq;
	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		vector<int> arr(10);
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if(i<10)
				arr[i] = num;
		}

		cin >> n;
		char cmd;
		int idx, num, number;
		for (int i = 0; i < n; i++) {
			cin >> cmd;
			cin >> idx >> num;
			for (int j = 0; j < min(idx, 10); j++)
				dq.push_back(arr[j]);
			for (int j = 0; j < num; j++) {
				cin >> number;
				if (dq.size() < 10)
					dq.push_back(number);
			}
			if (dq.size() < 10) {
				for (int j = idx; j < 10 && dq.size() < 10; j++)
					dq.push_back(arr[j]);
			}
			for (int j = 0; j < 10; j++) {
				arr[j] = dq.front();
				dq.pop_front();
			}
			dq.clear();
		}

		cout << '#' << test_case << ' ';
		for (int a : arr)
			cout << a << ' ';
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}