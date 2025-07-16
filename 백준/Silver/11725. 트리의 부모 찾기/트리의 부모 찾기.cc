#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

void BFS(vector<int> &tree, map<int, queue<int>> &graph, int point, vector<bool> &visited, queue<int> &to_visit){
    int node;
    while(!to_visit.empty()){
        node = to_visit.front();
        to_visit.pop();
        while(!graph[node].empty()){
            int next = graph[node].front();
            graph[node].pop();
            if(visited[next] == false){
                tree[next] = node;
                to_visit.push(next);
            }
        }
        visited[node] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    map<int, queue<int>> graph;
    int a, b;
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        graph[a].push(b);
        graph[b].push(a);
    }

    vector<int> tree(n+1, 0);
    vector<bool> visited(n+1, false);
    queue<int> to_visit;
    to_visit.push(1);
    BFS(tree, graph, 1, visited, to_visit);

    for(int i=2; i<n+1; i++)
        cout << tree[i] << '\n';
}