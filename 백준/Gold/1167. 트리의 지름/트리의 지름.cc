#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<bool> visited;

void DFS(int node) {
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i].first;
		int next_d = graph[node][i].second;

		if (visited[next])
			continue;

		dist[next] = dist[node] + next_d;
		DFS(next);
	}
}

int main() {
	cin >> n;
	graph.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, -1);
	visited.assign(n + 1, false);

	for (int i = 0; i < n; i++) {
		int node;
		cin >> node;

		int num, d;
		while (true) {
			cin >> num;
			if (num == -1)
				break;
			cin >> d;
			graph[node].push_back({ num, d });
		}
	}

	dist[1] = 0;
	DFS(1);

	int f = max_element(dist.begin(), dist.end()) - dist.begin();

	dist.assign(n + 1, -1);
	visited.assign(n + 1, false);

	dist[f] = 0;
	DFS(f);

	cout << *max_element(dist.begin(), dist.end()) << '\n';
}