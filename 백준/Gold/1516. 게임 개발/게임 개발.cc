#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
vector<int> times;
vector<vector<int>> pre;
vector<int> cnts;
queue<int> q;
vector<int> ans;

void Search() {
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : pre[now]) {
			cnts[next]--;
			if (cnts[next] == 0)
				q.push(next);
			ans[next] = max(ans[next], ans[now] + times[next]);
		}
	}
}

int main()
{
	cin >> n;
	times.assign(n + 1, 0);
	cnts.assign(n + 1, 0);
	ans.assign(n + 1, 0);
	pre.assign(n + 1, vector<int>());

	for (int i = 1; i < n + 1; i++) {
		cin >> times[i];
		while (true) {
			int p;
			cin >> p;
			if (p == -1)
				break;
			pre[p].push_back(i);
			cnts[i]++;
		}
	}

	for (int i = 1; i < n + 1; i++)
		if (cnts[i] == 0) {
			q.push(i);
			ans[i] = times[i];
		}

	Search();

	for (int i = 1; i < n + 1; i++)
		cout << ans[i] << '\n';
}