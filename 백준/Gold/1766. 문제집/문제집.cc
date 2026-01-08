#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
vector<int> cnts;
vector<vector<int>> graph;
priority_queue<int, vector<int>, greater<int>> pq;
queue<int> ans;

void Search() {
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		ans.push(now);

		for (int next : graph[now]) {
			cnts[next]--;
			if (cnts[next] == 0)
				pq.push(next);
		}
	}
}


int main(int argc, char** argv)
{
	cin >> n >> m;
	cnts.assign(n + 1, 0);
	graph.assign(n + 1, vector<int>());

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cnts[b]++;
		graph[a].push_back(b);
	}

	int start;
	for (int i = 1; i < n + 1; i++)
		if (cnts[i] == 0)
			pq.push(i);

	Search();

	while (!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop();
	}
}