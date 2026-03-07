#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		vector<int> ans;
		priority_queue<int> maxpq;
		priority_queue<int, vector<int>, greater<int>> minpq;

		int m; 
		cin >> m;
		for (int i = 1; i < m + 1; i++) {
			int num;
			cin >> num;
			maxpq.push(num);
			minpq.push(num);

			while (!maxpq.empty() && !minpq.empty() && maxpq.top() > minpq.top()) {
				maxpq.push(minpq.top());
				minpq.pop();
				minpq.push(maxpq.top());
				maxpq.pop();
			}

			if (i % 2 == 1)
				ans.push_back(minpq.top());
		}

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
}