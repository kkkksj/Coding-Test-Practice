#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int n, m, d;
vector<string> grass_before;
vector<string> grass_after;

bool BFS(int goal, queue<pair<int, int>> &q){
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    int cnt = 0;

    while(!q.empty()){
        int now_i = q.front().first;
        int now_j = q.front().second;
        q.pop();

        cnt++;
        visited[now_i][now_j] = true;

        for(int dir_i=-d; dir_i<=d; dir_i++){
            int next_i = now_i + dir_i;
            for(int dir_j=-d+abs(dir_i); dir_j<=d-abs(dir_i); dir_j++){
                int next_j = now_j + dir_j;
                if((next_i>=0 && next_i<n) && (next_j>=0 && next_j<m)){
                    if((visited[next_i][next_j] == false) && grass_before[next_i][next_j] == 'X'){
                        visited[next_i][next_j] = true;
                        if(grass_after[next_i][next_j] == 'O')
                            q.push({next_i, next_j});
                    }
                }
            }
        }
    }

    if(cnt == goal)
        return true;
    else
        return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    
    grass_before.resize(n);
    grass_after.resize(n);
    queue<pair<int, int>> q;

    for(int i=0; i<n; i++){
        cin >> grass_before[i];
        for(int j=0; j<m; j++)
            if(grass_before[i][j] == 'O')
                q.push({i, j});
    }

    cin >> d;

    int goal = 0;
    for(int i=0; i<n; i++){
        cin >> grass_after[i];
        for(int j=0; j<m; j++)
            if(grass_after[i][j] == 'O')
                goal++;
    }

    if(BFS(goal, q))    
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}