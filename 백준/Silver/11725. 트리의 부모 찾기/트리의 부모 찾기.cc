#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int>& tree, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                tree[next] = node;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<vector<int>> graph(n+1);
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> tree(n+1, 0);
    vector<bool> visited(n+1, false);

    BFS(tree, graph, visited);

    for (int i = 2; i <= n; i++)
        cout << tree[i] << '\n';
}
