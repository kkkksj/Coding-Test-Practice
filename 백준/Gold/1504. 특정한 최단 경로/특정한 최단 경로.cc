#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Info
{
    int num;
    int weight;
};

int n, m;
vector<vector<Info>> arr; 

void Dijkstra(int start, vector<long long> &dist){
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n+1, false);
    pq.push({dist[start], start});
    while(!pq.empty()){
        int node = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if (d != dist[node]) continue;  
        if (visited[node]) continue;
        visited[node] = true;
        for(int i=0; i<(int)arr[node].size(); i++){
            int next_node = arr[node][i].num;
            if(visited[next_node])    continue;
            int next_w = arr[node][i].weight;

            if(dist[next_node] > d+next_w){
                dist[next_node] = d+next_w;
                pq.push({dist[next_node], next_node});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.assign(n+1, vector<Info> ());
    for(int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        arr[a].push_back({b, w});
        arr[b].push_back({a, w});
    }

    int point1, point2;
    cin >> point1 >> point2;

    vector<long long> dist (n+1, INT_MAX);
    vector<long long> dist1 (n+1, INT_MAX);
    vector<long long> dist2 (n+1, INT_MAX);

    Dijkstra(1, dist);
    Dijkstra(point1, dist1);
    Dijkstra(point2, dist2);

    long long A = dist[point1] + dist1[point2] + dist2[n];
    long long B = dist[point2] + dist2[point1] + dist1[n];

    long long ans = min(A, B);
    cout << (ans >= INT_MAX ? -1 : ans) << '\n';
}