#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;

void DFS(map<int, stack<int>> &graph, vector<bool> &visited, int node){
    visited[node]=true;
    while(!graph[node].empty()){
        int next_node = graph[node].top();
        graph[node].pop();
        if(!visited[next_node])
            DFS(graph, visited, next_node);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<int, stack<int>> graph;
    set<int> node_s;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push(b);
        graph[b].push(a);
        node_s.insert(a);
        node_s.insert(b);
    }
    
    vector<bool> visited (n+1, false);
    int ans = 0;
    for(auto node = node_s.begin(); node != node_s.end(); node++)
        if(!visited[*node]){
            DFS(graph, visited, *node);
            ans++;
        }

    for(int i=1; i<n+1; i++){
        if(visited[i] == false)
            ans++;
    }
    cout << ans << '\n';
}