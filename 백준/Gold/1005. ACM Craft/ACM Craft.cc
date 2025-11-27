#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, k, w;
vector<int> times;
vector<int> cnts;
queue<int> q;
vector<vector<int>> graph;
vector<int> dp;

void Search() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : graph[now]) {
			cnts[next]--;
			if (dp[next] < dp[now] + times[next]) 
				dp[next] = dp[now] + times[next];
			if (cnts[next] == 0)
				q.push(next);
		}
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--) {
		cin >> n >> k;
		times.assign(n + 1, 0);
		cnts.assign(n + 1, 0);
		graph.assign(n + 1, vector<int>());
		dp.assign(n + 1, 0);
		
		for (int i = 1; i < n+1; i++)
			cin >> times[i];
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			cnts[b]++;
			graph[a].push_back(b);
		}
		for (int i = 1; i < n + 1; i++)
			if (cnts[i] == 0) {
				q.push(i);
				dp[i] = times[i];
			}

		cin >> w;

		Search();

		cout << dp[w] << '\n';
	}
}