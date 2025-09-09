#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int r, c;
vector<string> board;
vector<vector<bool>> visited;
int ans = 0;
vector<bool> alpha (26, false);
vector<int> i_list = {-1, 1, 0, 0};
vector<int> j_list = {0, 0, -1, 1};

void DFS(int i, int j, int cnt){
    visited[i][j] = true;
    alpha[board[i][j] - 'A'] = true;

    ans = max(ans, cnt);
    for(int d=0; d<4; d++){
        int next_i = i + i_list[d];
        int next_j = j + j_list[d];

        if(next_i<0 || next_i>=r || next_j<0 || next_j>=c || visited[next_i][next_j])
            continue;
        if(alpha[board[next_i][next_j] - 'A'] == false)
            DFS(next_i, next_j, cnt+1);
    }

    visited[i][j] = false;
    alpha[board[i][j] - 'A'] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   
    cin >> r >> c;
    board.assign(r, "");
    visited.assign(r, vector<bool> (c, false));
    for(int i=0; i<r; i++)
        cin >> board[i];
        
    DFS(0, 0, 1);

    cout << ans << '\n';
}