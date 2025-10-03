#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, v, e;
vector<vector<int>> graph;
vector<int> visited;

void BFS(int node){
    queue<int> q;   
    int c = 0;
    visited[node] = c;
    q.push(node);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(visited[now] == 0)
            c = 1;
        else 
            c = 0;
        
        for(int i=0; i<(int)graph[now].size(); i++){
            int next = graph[now][i];
            if(visited[next] == -1){
                visited[next] = c;
                q.push(next);
            }
        }
    }
}

bool IsBinary(){
    for(int i=1; i<v+1; i++)
        for(int j=0; j<(int)graph[i].size(); j++)
            if(visited[i] == visited[graph[i][j]])
                return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> v >> e;
        graph.assign(v+1, vector<int> ());
        visited.assign(v+1, -1);

        for(int i=0; i<e; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i=1; i<v+1; i++)
            if(visited[i]==-1)
                BFS(i);

        if(IsBinary())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}