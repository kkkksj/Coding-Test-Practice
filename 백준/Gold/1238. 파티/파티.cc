#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> dist;

void MidDist(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start][start] = 0;

	while (!pq.empty()) {
		int now_node = pq.top().second;
		int now_dist = pq.top().first;
		pq.pop();
		if (dist[start][now_node] != now_dist)
			continue;

		for (int i = 0; i < graph[now_node].size(); i++) {
			int next_node = graph[now_node][i].first;
			int next_dist = graph[now_node][i].second;

			if (dist[start][now_node] + next_dist < dist[start][next_node]) {
				dist[start][next_node] = dist[start][now_node] + next_dist;
				pq.push({ dist[start][next_node], next_node });
			}
		}
	}
}

int main()
{
	cin >> n >> m >> x;
	graph.assign(n + 1, vector<pair<int, int>>({}));
	dist.assign(n + 1, vector<int>(n + 1, INT_MAX));

	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;

		graph[a].push_back({ b, w });
	}

	for (int i = 1; i < n + 1; i++)
		MidDist(i);

	int ans = 0;
	for (int i = 1; i < n + 1; i++) 
		ans = max(dist[i][x] + dist[x][i], ans);
	
	cout << ans << '\n';
}