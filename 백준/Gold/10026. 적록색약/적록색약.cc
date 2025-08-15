#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<string> grid;

vector<int> i_list = {-1, 0, 1, 0};
vector<int> j_list = {0, -1, 0, 1};

void BFS1(vector<vector<bool>> &visited, int i, int j){
    char color = grid[i][j];
    queue<pair<int, int>> q;    
    q.push({i, j});

    while(!q.empty()){
        int now_i = q.front().first;
        int now_j = q.front().second;
        q.pop();        
        visited[now_i][now_j] = true;

        for(int dir=0; dir<4; dir++){
            int next_i = now_i + i_list[dir];
            int next_j = now_j + j_list[dir];

            if((next_i>=0 && next_i<n) && (next_j>=0 && next_j<n))
                if(grid[next_i][next_j] == color && visited[next_i][next_j] == false){
                    q.push({next_i, next_j});
                    visited[next_i][next_j] = true;
                }
        }
    }
}


void BFS2(vector<vector<bool>> &visited, int i, int j){
    char color = grid[i][j];
    queue<pair<int, int>> q;    
    q.push({i, j});

    while(!q.empty()){
        int now_i = q.front().first;
        int now_j = q.front().second;
        q.pop();        
        visited[now_i][now_j] = true;

        for(int dir=0; dir<4; dir++){
            int next_i = now_i + i_list[dir];
            int next_j = now_j + j_list[dir];

            if((next_i>=0 && next_i<n) && (next_j>=0 && next_j<n))
                if(visited[next_i][next_j] == false){
                    if((color=='R' || color=='G') && (grid[next_i][next_j]=='R' || grid[next_i][next_j]=='G')){
                        q.push({next_i, next_j});
                        visited[next_i][next_j] = true;
                    }
                    else if(color == grid[next_i][next_j]){
                        q.push({next_i, next_j});
                        visited[next_i][next_j] = true;
                    }
                }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    grid.resize(n);

    for(int i=0; i<n; i++)
        cin >> grid[i];
    
    vector<vector<bool>> visited(n, vector<bool> (n, false));
    int ans1 = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(visited[i][j] == false){
                BFS1(visited, i, j);
                ans1++;
            }

    visited.clear();
    visited.resize(n, vector<bool> (n, false));
    int ans2 = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(visited[i][j] == false){
                BFS2(visited, i, j);
                ans2++;
            }
    
    cout << ans1 << ' ' << ans2 << '\n';
}