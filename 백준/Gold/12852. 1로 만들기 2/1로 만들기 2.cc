#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> dist;
vector<int> parent;	// 경로 출력을 위함

void BFS() {
	parent[1] = 0;
	dist[1] = 0;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int nownum = q.front();
		q.pop();

		if (nownum == n) {
			cout << dist[nownum] << '\n';	// 연산 횟수 출력
			int pointer = nownum;
			while (parent[pointer] != -1) {	// 경로 출력
				cout << pointer << ' ';
				pointer = parent[pointer];
			}
			return;
		}

		int nexts[3] = { nownum + 1, nownum * 2, nownum * 3 };
		for (int i = 0; i < 3; i++) {
			int nextnum = nexts[i];
			if (nextnum > n || dist[nextnum] != -1)
				continue;

			dist[nextnum] = dist[nownum] + 1;
			parent[nextnum] = nownum;
			q.push({ nextnum });
		}
	}
	return;
}

int main() {
	cin >> n;
	dist.assign(n + 1, -1);
	parent.assign(n + 1, -1);

	BFS();
}