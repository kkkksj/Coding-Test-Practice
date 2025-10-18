#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> plan;

bool BFS(int start, int end){
    vector<bool> visited (n+1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(now == end)
            return true;
        
        for(int next : graph[now]){
            if(visited[next])
                continue;
            visited[next] = true;
            q.push(next);
        }
    }

    return false;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    graph.assign(n+1, vector<int> ());
    plan.assign(m, 0);

    for(int i=1; i<n+1; i++)
        for(int j=1; j<n+1; j++){
            int c;
            cin >> c;
            if(c==1)
                graph[i].push_back(j);
        }
    
    for(int i=0; i<m; i++)
        cin >> plan[i];
    
    int start, end;
    for(int i=1; i<m; i++){
        start = plan[i-1];
        end = plan[i];

        if(BFS(start, end) == false){
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
}