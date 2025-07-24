#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;
void BFS(vector<vector<int>> &graph, vector<int> &dist){
    queue<int> q;
    q.push(x);
    dist[x] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int next : graph[node])
            if(dist[next] == -1){
                dist[next] = dist[node] + 1;
                q.push(next);
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k >> x;

    vector<vector<int>> graph(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    vector<int> dist(n+1, -1);
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