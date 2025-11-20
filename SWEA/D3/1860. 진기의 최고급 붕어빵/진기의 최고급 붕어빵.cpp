#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n, m, k;
		cin >> n >> m >> k;

		while (n--) {
			int num;
			cin >> num;
			pq.push(num);
		}

		int sell = 0;
		int sec;
		int bread;
		string ans = "Possible";
		while(!pq.empty()) {
			sec = pq.top();
			pq.pop();
			sell++;
			bread = (sec / m) * k;
			
			if (bread - sell < 0) {
				ans = "Impossible";
				break;
			}
		}

		cout << '#' << test_case << ' ' << ans << '\n';

		while (!pq.empty())
			pq.pop();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}