#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

void DFS(map<int, vector<int>> &graph, int node, vector<int> &visited, int ans){
    visited[node] = ans;
    for(int next_node : graph[node])
        if(visited[next_node] == -1)
            DFS(graph, next_node, visited, ans+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    int m;
    cin >> m;

    map<int, vector<int>> graph;
    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> visited(n+1, -1);
    visited[a] = true;
    int ans = 0;
    DFS(graph, a, visited, ans);

    cout << visited[b];
}