#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, r, q;
vector<int> tree;
vector<vector<int>> graph;

void DFS(int node, int p){
    tree[node] = 1;
    for(int next : graph[node]){
        if(next == p) continue;
        DFS(next, node);
        tree[node] += tree[next];
    }
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cin >> n >> r >> q;

    graph.assign(n+1, vector<int> ());
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    tree.assign(n+1, 0);
    DFS(r, 0);

    for(int i=0; i<q; i++){
        int query;
        cin >> query;
        cout << tree[query] << '\n';
    }
}