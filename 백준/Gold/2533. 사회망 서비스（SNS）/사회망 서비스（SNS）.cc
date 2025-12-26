#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int n;
vector<vector<int>> tree;
vector<vector<int>> dp;
vector<bool> visited;

void Search(int node) {
	dp[node][0] = 1;

	for (int child : tree[node]) {
		if (visited[child])
			continue;

		visited[child] = true;
		Search(child);

		dp[node][1] += dp[child][0];
		dp[node][0] += min(dp[child][0], dp[child][1]);
	}
}

int main() {
	cin >> n;
	tree.assign(n + 1, vector<int>());
	dp.assign(n + 1, vector<int>(2, 0));
	visited.assign(n + 1, false);

	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	visited[1] = true;
	Search(1);

	cout << min(dp[1][0], dp[1][1]) << '\n';
}