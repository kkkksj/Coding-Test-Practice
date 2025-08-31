#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<string> treasure_map;
vector<int> i_list = {-1, 1, 0, 0};
vector<int> j_list = {0, 0, -1, 1};

int BFS(int i, int j){
    vector<vector<int>> dist(n, vector<int> (m, -1));
    dist[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    int ret = 0;
    while(!q.empty()){
        int now_i = q.front().first;
        int now_j = q.front().second;
        q.pop();
        ret = max(ret, dist[now_i][now_j]);

        for(int d=0; d<4; d++){
            int next_i = now_i + i_list[d];
            int next_j = now_j + j_list[d];
            if(next_i<0 || next_i>=n || next_j<0 || next_j>=m)
                continue;
            if(treasure_map[next_i][next_j] == 'L')
                if(dist[next_i][next_j] == -1){
                    dist[next_i][next_j] = dist[now_i][now_j] + 1;
                    q.push({next_i, next_j});
                }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    treasure_map.assign(n, "");

    for(int i=0; i<n; i++)
        cin >> treasure_map[i];
    
    int ans = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(treasure_map[i][j] == 'L')
                ans = max(ans, BFS(i, j));
        }

    cout << ans << '\n';
}