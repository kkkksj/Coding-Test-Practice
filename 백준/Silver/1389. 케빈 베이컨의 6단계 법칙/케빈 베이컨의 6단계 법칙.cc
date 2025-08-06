#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int BFS(vector<vector<int>> &friends, int start){
    int ret = 0;
    for(int end=1; end<n+1; end++){
        if(start == end)
            continue;
        
        vector<int> dist(n+1, -1);
        dist[start] = 0;

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == end){
                ret += dist[node];
                break;
            }

            for(int next_node : friends[node])
                if(dist[next_node] == -1){
                    q.push(next_node);
                    dist[next_node] = dist[node] + 1;
                }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> friends (n+1, vector<int> ());
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    int ans_total = 500000;
    int ans = 0;
    for(int node=1; node<n+1; node++){
        int total = BFS(friends, node);
        if(total < ans_total){
            ans_total = total;
            ans = node;
        }
    }

    cout << ans << '\n';
}