#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
int cnt = 1;
void DFS(vector<vector<int>> &graph, vector<int> &visited, int node){
    visited[node] = cnt++;

    sort(graph[node].begin(), graph[node].end());
    for(int next : graph[node])
        if(visited[next] == 0)
            DFS(graph, visited, next);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m ,r;
    cin >> n >> m >> r;

    int u, v;
    vector<vector<int>> graph (n+1);
    for(int i=0; i<m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n+1, 0);
    DFS(graph, visited, r);

    for(int i=1; i<n+1; i++)
        cout << visited[i] << '\n';
}