#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
int ans = 1;

void DFS(int node, int cnt) {
	ans = max(cnt, ans);

	for (int next : graph[node]) {
		if (visited[next])
			continue;
		visited[next] = true;
		DFS(next, cnt + 1);
		visited[next] = false;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> m;

		graph.assign(n+1, vector<int>());
		visited.assign(n + 1, false);
		while (m--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		ans = 1;
		for (int i = 1; i < n + 1; i++)
			DFS(i, 0);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}