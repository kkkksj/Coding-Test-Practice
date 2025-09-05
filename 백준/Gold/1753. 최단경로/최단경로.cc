#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int v, e;
vector<vector<pair<int, int>>> graph;

struct CMP{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.second != b.second)
            return a.second > b.second;
        return a.first > b.first;
    }
};


void Dijkstra(int start){
    vector<int> dist (v+1, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, CMP> pq;
    pq.push(make_pair(start, dist[start]));

    vector<bool> visited(v+1, false);

    while(!pq.empty()){
        int node = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        
        if (d != dist[node]) continue; 
        visited[node] = true;

        for(pair<int, int> info : graph[node]){
            int next_node = info.first;
            int next_d = info.second;

            if(visited[next_node])
                continue;
            
            if(dist[next_node] > d+next_d){
                dist[next_node] = d+next_d;
                pq.push(make_pair(next_node, dist[next_node]));
            }
        }
    }

    for(int i=1; i<v+1; i++){
        int d = dist[i];
        if(d == INT_MAX)
            cout << "INF" << '\n';
        else
            cout << d << '\n';
    }
}

void MakeGraph(int a, int b, int w){
    for(pair<int, int> &tmp : graph[a]){
        if(tmp.first == b){
            tmp.second = min(tmp.second, w);
            return ;
        }
    }
    graph[a].push_back(make_pair(b, w));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> v >> e;
    graph.assign(v+1, vector<pair<int, int>> ());

    int start;
    cin >> start;

    int a, b, w;
    while(e--){
        cin >> a >> b >> w;
        MakeGraph(a, b, w);
    }

    Dijkstra(start);
}