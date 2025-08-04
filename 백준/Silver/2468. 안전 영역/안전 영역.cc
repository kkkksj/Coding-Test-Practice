#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

vector<int> i_list = {-1, 0, 1, 0};
vector<int> j_list = {0, -1, 0, 1};

void DFS(vector<vector<int>> &grid, vector<vector<bool>> &visited, int h, int i, int j){
    visited[i][j] = true;

    for(int idx=0; idx<4; idx++){
        int next_i = i + i_list[idx];
        int next_j = j + j_list[idx];

        if((next_i>=0 && next_i<n) && (next_j>=0 && next_j<n))
            if(grid[next_i][next_j] > h)
                if(visited[next_i][next_j] == false)
                    DFS(grid, visited, h, next_i, next_j);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    vector<vector<int>> grid(n, vector<int> (n));
    int max_h = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            max_h = max(max_h, grid[i][j]);
        }

    int ans = 0;
    for(int h=0; h<max_h+1; h++){
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        int d = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(visited[i][j] == false)
                    if(grid[i][j] > h){
                        DFS(grid, visited, h, i, j);
                        d++;
                    }
        ans = max(ans, d);
    }

    cout << ans << '\n';
}