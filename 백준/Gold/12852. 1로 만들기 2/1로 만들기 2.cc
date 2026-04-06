#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> dist;
struct QInfo {
	int num, dist;
	vector<int> ans_vec;
};

void BFS() {
	dist[1] = 0;
	queue<QInfo> q;
	q.push({ 1, 0, {1} });

	while (!q.empty()) {
		QInfo now = q.front();
		q.pop();

		if (now.num == n) {
			cout << now.dist << '\n';
			for (auto it = now.ans_vec.rbegin(); it != now.ans_vec.rend(); it++)
				cout << *it << ' ';
		}

		int three_times = now.num * 3;
		if (three_times <= n && dist[three_times] == 0) {
			dist[three_times] = now.dist + 1;
			now.ans_vec.push_back(three_times);
			q.push({ three_times, dist[three_times], now.ans_vec });
			now.ans_vec.pop_back();
		}

		int twice = now.num * 2;
		if (twice <= n && dist[twice] == 0) {
			dist[twice] = now.dist + 1;
			now.ans_vec.push_back(twice);
			q.push({ twice, dist[twice], now.ans_vec });
			now.ans_vec.pop_back();
		}

		int plusone = now.num + 1;
		if (plusone <= n && dist[plusone] == 0) {
			dist[plusone] = now.dist + 1;
			now.ans_vec.push_back(plusone);
			q.push({ plusone, dist[plusone], now.ans_vec });
			now.ans_vec.pop_back();
		}
	}
}

int main() {
	cin >> n;
	dist.assign(n + 1, 0);

	vector<int> ans_vec;
	BFS();
}