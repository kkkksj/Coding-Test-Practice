#include <iostream>
#include <vector>
#include <queue>

#define MAXV 20001
#define INF 1000000000

using namespace std;

struct Node {
    int v;
    int dist;

    bool operator<(const Node& right) const {
        return dist > right.dist;
    }
};

vector<pair<int, int>> graph[MAXV];
int dist[MAXV];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    int start;
    cin >> start;

    for (int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        graph[from].push_back({to, cost});
    }

    for (int i = 1; i <= v; i++)
        dist[i] = INF;

    priority_queue<Node> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if (now.dist > dist[now.v])
            continue;

        for (auto next : graph[now.v]) {
            int next_v = next.first;
            int next_dist = now.dist + next.second;

            if (next_dist >= dist[next_v])
                continue;

            dist[next_v] = next_dist;
            pq.push({next_v, next_dist});
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }

    return 0;
}