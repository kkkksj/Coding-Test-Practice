#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<limits.h>

using namespace std;

int n, m, dep, des;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<int> pre;

void BFS() {
	dist[dep] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, dep });
	
	while (!pq.empty()) {
		int now = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		if (d != dist[now])
			continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int w = graph[now][i].second;

			if (dist[next] > dist[now] + w) {
				dist[next] = dist[now] + w;
				pq.push({ dist[next], next });
				pre[next] = now;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	graph.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, INT_MAX);
	pre.assign(n+1, 0);

	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back({ b ,w });
	}

	cin >> dep >> des;
	BFS();

	cout << dist[des] << '\n';
	int node = des;
	stack<int> ans;
	while (node != 0) {
		ans.push(node);
		node = pre[node];
	}
	cout << ans.size() << '\n';
	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
}