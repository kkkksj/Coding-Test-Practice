#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

void DFS(vector<bool> &visited, map<int, set<int>> &graph, int node){
    cout << node << ' ';
    visited[node] = true;

    set<int> &connected = graph[node];
    for(auto n = connected.begin(); n != connected.end(); n++)
        if(!visited[*n]){
            visited[*n] = true;
            DFS(visited, graph, *n);
        }
    return ;
}

void BFS(vector<bool> &visited, map<int, set<int>> &graph, int &node){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        node = q.front();
        cout << node << ' ';
        q.pop();
        set<int> &connected = graph[node];
        for(auto n = connected.begin(); n != connected.end(); n++)
            if(!visited[*n]){
                visited[*n] = true;
                q.push(*n);
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, v;
    cin >> n >> m >> v;

    map<int, set<int>> graph;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    vector<bool> visited (n+1, false);
    DFS(visited, graph, v);
    cout << '\n';
    visited = vector<bool> (n+1, false);
    BFS(visited, graph, v);
}