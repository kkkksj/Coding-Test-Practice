#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<int> cnts;
vector<vector<int>> graph;
queue<int> ans;
queue<int> q;

void Search() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ans.push(now);

		for (int next : graph[now]) {
			cnts[next]--;
			if (cnts[next] == 0)
				q.push(next);
		}
	}
}

int main()
{
	cin >> n >> m;

	cnts.assign(n + 1, 0);
	graph.assign(n + 1, vector<int>());

	while(m--){
		int a, b;
		cin >> a >> b;

		cnts[b]++;
		graph[a].push_back(b);
	}

	int start;
	for (int i = 1; i < n + 1; i++) 
		if (cnts[i] == 0) 
			q.push(i);
		
	Search();

	while (!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop();
	}
}