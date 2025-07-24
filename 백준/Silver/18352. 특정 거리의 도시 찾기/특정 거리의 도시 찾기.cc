#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;
vector<int> ans;
void BFS(map<int, vector<int>> graph, queue<int> &q, vector<int> &dist){
    vector<bool> visited (n+1, false);
    visited[x] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int next : graph[node])
            if(visited[next] == false){
                dist[next] = dist[node] + 1;
                if(dist[next] == k)
                    ans.push_back(next);
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

    queue<int> q;
    q.push(x);
    vector<int> dist(n+1, 0);
    BFS(graph, q, dist);

    if(ans.size()){
        sort(ans.begin(), ans.end());
        for(int num : ans)
            cout << num << '\n';
    }
    else
        cout << -1 << '\n';
}