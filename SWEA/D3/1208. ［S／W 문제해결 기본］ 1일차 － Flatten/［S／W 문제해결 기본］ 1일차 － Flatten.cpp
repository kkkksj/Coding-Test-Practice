#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n;
priority_queue<int> bpq;
priority_queue<int, vector<int>, greater<int>> spq;

int Find() {
	int big, small;
	for (int i = 0; i < n; i++) {
		big = bpq.top();
		bpq.pop();
		small = spq.top();
		spq.pop();

		if (big - small <= 1)
			return big - small;
		bpq.push(big - 1);
		spq.push(small + 1);
	}
	return bpq.top() - spq.top();
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		
		bpq = priority_queue<int>();
		spq = priority_queue<int, vector<int>, greater<int>>();


		int num;
		for (int i = 0; i < 100; i++) {
			cin >> num;
			bpq.push(num);
			spq.push(num);
		}

		cout << '#' << test_case << ' ' << Find() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}