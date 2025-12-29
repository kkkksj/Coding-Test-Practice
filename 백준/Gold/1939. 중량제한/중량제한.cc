#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int n, m, dep, dest;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void BFS() {
	priority_queue<pair<int, int>> pq;
	dist[dep] = INT_MAX;
	pq.push({ INT_MAX, dep });

	while (!pq.empty()) {
		int d = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] != d)
			continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int cost = min(d, graph[now][i].second);
			if (dist[next] < cost) {
				dist[next] = cost;
				pq.push({ cost, next });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	graph.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, -1);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	
	cin >> dep >> dest;

	BFS();

	cout << dist[dest] << '\n';
}