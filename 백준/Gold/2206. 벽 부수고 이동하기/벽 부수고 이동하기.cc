#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
vector<string> info;

vector<int> i_list = {-1, 1, 0, 0};
vector<int> j_list = {0, 0, -1, 1};

void BFS(int i, int j){
    vector<vector<vector<int>>> dist(n, vector<vector<int>> (m, vector<int>(2, 0)));
    dist[0][0][0] = 1;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});

    while(!q.empty()){
        int now_i = get<0>(q.front());
        int now_j = get<1>(q.front());
        int chance = get<2>(q.front());
        q.pop();

        if(now_i==n-1 && now_j==m-1){
            cout << dist[now_i][now_j][chance] << '\n';
            return;    
        }

        for(int d=0; d<4; d++){
            int next_i = now_i + i_list[d];
            int next_j = now_j + j_list[d];

            if(next_i<0 || next_i>=n || next_j<0 || next_j>=m)
                continue;
            
            if(info[next_i][next_j] == '1' && chance==0 && dist[next_i][next_j][1] == 0){
                dist[next_i][next_j][1] = dist[now_i][now_j][chance]+1;
                q.push({next_i, next_j, 1});
            }
            else if(info[next_i][next_j] == '0' && dist[next_i][next_j][chance] == 0){
                dist[next_i][next_j][chance] = dist[now_i][now_j][chance]+1;
                q.push({next_i, next_j, chance});
            }
        }
    }
    cout << -1 << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    
    info.assign(n, "");
    for(int i=0; i<n; i++)
        cin >> info[i];
    
    BFS(0, 0);
}