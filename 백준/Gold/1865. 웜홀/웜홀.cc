#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

struct Info {
	int s, e, t;
};

int n, m, w;
vector<Info> graph;
vector<int> dist;

bool BellmanFord() {
	for(int i=0; i<n+1; i++)
		for (int j = 0; j < graph.size(); j++) {
			int s = graph[j].s;
			int e = graph[j].e;
			int t = graph[j].t;

			if (dist[s] + t < dist[e]) {
				if (i == n)
					return true;
				dist[e] = dist[s] + t;
			}
		}

	return false;
}

int main()
{
	int T;
	cin >> T;

	while (T--) {
		cin >> n >> m >> w;
		graph.assign({});
		dist.assign(n + 1, 22222);

		int s, e, t;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			graph.push_back({ s, e, t });
			graph.push_back({ e, s, t });
		}

		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			graph.push_back({ s, e, -t });
		}

		if (BellmanFord())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}