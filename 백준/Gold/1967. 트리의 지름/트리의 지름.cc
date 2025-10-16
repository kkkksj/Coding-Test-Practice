#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<bool> visited;
int ans = 0;
int e = 0;

void dfs(int node, int len, vector<vector<pair<int, int>>> &graph){
    if(visited[node])
        return;
    
    visited[node] = true;
    if(ans < len){
        ans = len;
        e = node;
    }

    for(int i=0; i<graph[node].size(); i++)
        dfs(graph[node][i].first, len+graph[node][i].second, graph);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<pair<int, int>>> graph (n+1); 
    visited.assign(n+1, false);
    for(int i=0; i<n-1; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});   
    }

    dfs(1, 0, graph);
    ans = 0;
    visited.assign(n+1, false);

    dfs(e, 0, graph);

    cout << ans << '\n';
}