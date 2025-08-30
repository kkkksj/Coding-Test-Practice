#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int n, int k, int s, vector<vector<int>> &graph){
    queue<int> q;
    q.push(s);

    int ret = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(node == k)
            continue;
        
        if(graph[node].empty() || (graph[node].size()==1 && graph[node].front()==k))
            ret++;
        else{
            for(int next_node : graph[node])
                q.push(next_node);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<vector<int>> graph(n, vector<int> ());
    int start;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;

        if(num == -1){
            start = i;
            continue;
        }
        
        graph[num].push_back(i);
    }

    int k;
    cin >> k;
    
    cout << BFS(n, k, start, graph) << '\n';
}