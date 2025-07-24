#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;
void BFS(map<int, vector<int>> graph, vector<int> &dist){
    vector<bool> visited (n+1, false);
    visited[x] = true;
    queue<int> q;
    q.push(x);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int next : graph[node])
            if(visited[next] == false){
                dist[next] = dist[node] + 1;
                visited[next] = true;
                q.push(next);
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k >> x;

    map<int, vector<int>> graph;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    vector<int> dist(n+1, 0);
    BFS(graph, dist);

    vector<int> ans;
    for(int i=1; i<n+1; i++)
        if(dist[i] == k)
            ans.push_back(i);
    if(ans.empty())
        cout << -1 << '\n';
    else
        for(int tmp : ans)
            cout << tmp << '\n';
}