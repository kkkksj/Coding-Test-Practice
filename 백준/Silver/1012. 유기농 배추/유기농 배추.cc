#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

void DFS(vector<vector<bool>> &graph, int x, int y, int n, int m){
    vector<int> i_list = {-1, 0, 1, 0};
    vector<int> j_list = {0, -1, 0, 1};
    graph[y][x] = false;

    for(int i=0; i<4; i++){
        int new_x = x+i_list[i];
        int new_y = y+j_list[i];
        if((new_x>=0 && new_x<m) && (new_y>=0 && new_y<n) && graph[new_y][new_x]){
            DFS(graph, new_x, new_y, n, m);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n, m, v;
        cin >> m >> n >> v;

        vector<vector<bool>> graph (n, vector<bool> (m, false));
        queue<vector<int>> q;
        for(int j=0; j<v; j++){
            int x, y;
            cin >> x >> y;
            graph[y][x] = true;
            q.push({x, y});
        }

        int ans = 0;
        while(!q.empty()){          
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();
            if(graph[y][x]){
                DFS(graph, x, y, n, m);
                ans++;
            }
        }

        cout << ans << '\n';
        cout.flush();
    }
}