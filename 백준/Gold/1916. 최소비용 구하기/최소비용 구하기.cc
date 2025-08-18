#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> cost; 

int Dijk(int start, int end){
    vector<int> dist(n+1, INT_MAX);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    vector<bool> visited (n+1, false);

    while(!q.empty()){
        int node = q.front();
        if(node == end)
            return dist[end];
        q.pop();
        visited[node] = true;
        for(int i=1; i<n+1; i++){
            if(visited[i] == false)
                if(cost[node][i] != INT_MAX)
                    if(dist[i] > dist[node] + cost[node][i])
                        dist[i] = dist[node] + cost[node][i];
        }

        int next_i = 0;
        int next_n = INT_MAX;
        for(int i=1; i<n+1; i++)
            if(visited[i] == false)
                if(dist[i] < next_n){
                    next_n = dist[i];
                    next_i = i;
                }
        q.push(next_i);
    }

    return dist[end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;

    cost.resize(n+1, vector<int> (n+1, INT_MAX));
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }

    int dep, dest;
    cin >> dep >> dest;
    cout << Dijk(dep, dest) << '\n';
}