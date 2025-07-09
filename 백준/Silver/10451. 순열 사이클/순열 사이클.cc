#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

void DFS(map<int, int> &graph, vector<bool> &visited, int node, queue<int> &list){
    int next_node = graph[node];
    if(visited[next_node] == false){   //이미 방문한 노드가 아니라면
        visited[next_node] = true;
        DFS(graph, visited, next_node, list);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for(int c=0; c<t; c++){
        int n;
        cin >> n;

        int num;
        map<int, int> graph;
        vector<bool> visited (n+1);
        queue<int> list;
        for(int i=1; i<n+1; i++){
            cin >> num;
            graph[i] = num;
            list.push(num);
        }

        int ans = 0;
        int node;
        while(!list.empty()){
            node = list.front();
            list.pop();
            if(visited[node] == false){
                visited[node] = true;
                DFS(graph, visited, node, list);
                ans++;
            }
        }
        cout << ans << '\n';
    }
}