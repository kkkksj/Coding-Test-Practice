#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> parents;
vector<int> depth;

void DFS(int node, int d) {
	visited[node] = true;
	depth[node] = d;
	for (int next : graph[node]) {
		if (visited[next])
			continue;
		parents[next] = node;
		DFS(next, d + 1);
	}
}

int LCA(int a, int b) {
	while (parents[a] != parents[b]) {
		if (depth[a] < depth[b])
			b = parents[b];
		else
			a = parents[a];
	}
	while (a != b) {
		a = parents[a];
		b = parents[b];
	}
	return a;
}

int main() {
	cin >> n;
	graph.assign(n + 1, vector<int>());
	visited.assign(n + 1, false);
	parents.assign(n + 1, 0);
	depth.assign(n + 1, 0);

	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1, 0);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
}