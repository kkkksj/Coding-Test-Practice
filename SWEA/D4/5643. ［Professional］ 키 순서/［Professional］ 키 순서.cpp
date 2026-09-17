#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

#define MAXN 500

using namespace std;

int n, m;
vector<int> graph[MAXN + 1];
vector<int> rev_graph[MAXN + 1];
bool visited[MAXN + 1];

int Dfs(int now, vector<int> adj[]) {
	visited[now] = true;

	int cnt = 0;

	for(int next : adj[now]) {
		if (visited[next])
			continue;

		cnt += Dfs(next, adj) + 1;
	}

	return cnt;
}

int main(int argc, char** argv)
{
    int t;
	cin >> t;

	for(int test_case=1; test_case<=t; test_case++) {
		cin >> n;
		cin >> m;

		for(int i=1; i<=n; i++) {
			graph[i].clear();
			rev_graph[i].clear();
		}

		for(int i=0; i<m; i++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			rev_graph[b].push_back(a);
		}

		int answer = 0;

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
				visited[j] = false;

			int taller = Dfs(i, graph);

			for(int j=1; j<=n; j++)
				visited[j] = false;

			int shorter = Dfs(i, rev_graph);

			if (taller + shorter == n - 1)
				answer++;
		}

		cout << "#" << test_case << " " << answer << '\n';
	}

	return 0;
}