#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<limits.h>

using namespace std;

int n;
vector<int> people;
vector<vector<int>> graph;
vector<int> group;
int ans = INT_MAX;

bool IsAConnected(int acnt) {
	vector<bool> visited(n + 1, false);
	queue<int> q;
	int cnt = 0;
	for (int i = 1; i < n + 1; i++)
		if (group[i] == 1) {
			visited[i] = true;
			q.push(i);
			break;
		}

	while (!q.empty() && cnt < acnt) {
		int now = q.front();
		q.pop();
		cnt++;

		for (int next : graph[now]) {
			if (visited[next] || group[next] == 2)
				continue;
			visited[next] = true;
			q.push(next);
		}
	}

	if (cnt == acnt)
		return true;
	return false;
}

bool IsBConnected(int bcnt) {
	vector<bool> visited(n + 1, false);
	queue<int> q;
	int cnt = 0;
	for(int i=1; i<n+1; i++)
		if (group[i] == 2) {
			visited[i] = true;
			q.push(i);
			break;
		}

	while (!q.empty() && cnt < bcnt) {
		int now = q.front();
		q.pop();
		cnt++;

		for (int next : graph[now]) {
			if (visited[next] || group[next] == 1)
				continue;
			visited[next] = true;
			q.push(next);
		}
	}

	if (cnt == bcnt)
		return true;
	return false;
}

int Cal() {
	int agroup = 0, bgroup = 0;
	for (int i = 1; i < n + 1; i++) {
		if (group[i] == 1)
			agroup += people[i];
		else
			bgroup += people[i];
	}
	if (agroup > bgroup)
		return agroup - bgroup;
	return bgroup - agroup;
}

void DFS(int start, int cnt) {
	int bcnt = n - cnt;
	if (cnt >= 1 && bcnt >= 1) 
		if (IsAConnected(cnt) && IsBConnected(bcnt))
			ans = min(ans, Cal());
	
	for (int i = start; i < n + 1; i++) {
		if (group[i] == 1)	continue;
		group[i] = 1;
		DFS(i + 1, cnt + 1);
		group[i] = 2;
	}
}

int main() {
	cin >> n;
	people.assign(n + 1, 0);
	graph.assign(n + 1, vector<int>());
	group.assign(n + 1, 2);

	for (int i = 1; i < n + 1; i++)
		cin >> people[i];

	int num, b;
	for (int a = 1; a < n + 1; a++) {
		cin >> num;
		while (num--) {
			cin >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}

	DFS(1, 0);

	if (ans == INT_MAX)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}