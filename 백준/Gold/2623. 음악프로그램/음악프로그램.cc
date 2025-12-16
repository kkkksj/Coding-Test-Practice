#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<int> cnts;
vector<vector<int>> graph;
queue<int> q;
vector<int> ans;

void Search() {
	int num;
	while (!q.empty()) {
		num = q.front();
		q.pop();
		ans.push_back(num);

		for (int next : graph[num]) {
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

	int t, a, b;
	while(m--) {
		cin >> t;
		cin >> a;
		for (int i = 1; i < t; i++) {
			cin >> b;
			cnts[b]++;
			graph[a].push_back(b);
			a = b;
		}
	}

	for (int i = 1; i < n + 1; i++) 
		if (cnts[i] == 0)
			q.push(i);
	
	Search();

	if (ans.size() != n) {
		cout << 0 << '\n';
		return 0;
	}
	for (int a : ans)
		cout << a << '\n';
}