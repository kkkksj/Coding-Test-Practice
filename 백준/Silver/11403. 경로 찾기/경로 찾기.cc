#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;

bool BFS(vector<vector<int>> &graph, int start, int dest){
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(node == dest && visited[node])
            return true;
        
        for(int next_node : graph[node])
            if(visited[next_node] == false){
                visited[next_node] = true;
                q.push(next_node);
            }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    vector<vector<int>> graph(n, vector<int>());
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            bool connected;
            cin >> connected;
            if(connected)
                graph[i].push_back(j);
        }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << BFS(graph, i, j) << ' ';
        cout << '\n';
    }
}