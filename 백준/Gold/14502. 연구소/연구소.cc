#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int n, m;
vector<vector<int>> lab;

vector<int> i_list = {-1, 1, 0, 0};
vector<int> j_list = {0, 0, -1, 1};

int BFS(int i, int j, vector<vector<bool>> &visited){
    int ret = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    while(!q.empty()){
        int now_i = q.front().first;
        int now_j = q.front().second;
        q.pop();
        ret++;

        for(int d=0; d<4; d++){
            int next_i = now_i + i_list[d];
            int next_j = now_j + j_list[d];
            if(next_i<0 || next_i>=n || next_j<0 || next_j>=m || visited[next_i][next_j]==true)
                continue;
            if(lab[next_i][next_j] == 0){
                q.push({next_i, next_j});
                visited[next_i][next_j] = true;
            }
        }
    }

    return ret;
}

int Find(){
    int ret = 0;
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(visited[i][j] == true)
                continue;
            if(lab[i][j] == 2)
                ret += BFS(i, j, visited);
        }
    
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    lab.assign(n, vector<int> (m));

    vector<pair<int, int>> zero_list;
    int ones = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 0)
                zero_list.push_back({i, j});
            else if(lab[i][j] == 1)
                ones++;
        }
    
    int zero = (int)zero_list.size();
    int ans = 0;
    for(int i=0; i<zero-2; i++){
        lab[zero_list[i].first][zero_list[i].second] = 1;
        for(int j=i+1; j<zero-1; j++){
            lab[zero_list[j].first][zero_list[j].second] = 1;
            for(int k=j+1; k<zero; k++){
                lab[zero_list[k].first][zero_list[k].second] = 1;
                int tmp = n*m - ones - 3 - Find();
                ans = max(tmp, ans);
                lab[zero_list[k].first][zero_list[k].second] = 0;
            }
            lab[zero_list[j].first][zero_list[j].second] = 0;
        }
        lab[zero_list[i].first][zero_list[i].second] = 0;
    }

    cout << ans << '\n';
}