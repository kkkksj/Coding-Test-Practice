#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int n;
queue<pair<int, char>> q;
deque<pair<int, int>> dq;
vector<vector<int>> grid;
int dir = 0;

vector<int> i_list = {0, 1, 0, -1};
vector<int> j_list = {1, 0, -1, 0};

bool Move(){
    int head_i = dq.front().first;
    int head_j = dq.front().second;
    int next_i = head_i+i_list[dir];
    int next_j = head_j+j_list[dir];    // 머리 옮기기
    
    if(next_i<0 || next_i>=n || next_j<0 || next_j>=n || grid[next_i][next_j]==0)
        return true;

    dq.push_front({next_i, next_j});

    if(grid[next_i][next_j] == -1){
        int tail_i = dq.back().first;
        int tail_j = dq.back().second;
        dq.pop_back();
        grid[tail_i][tail_j] = -1; // 꼬리 지우기
    }
    
    grid[next_i][next_j] = 0;   // 머리 표시하기

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    grid.assign(n, vector<int> (n, -1));
    grid[0][0] = 0;
    dq.push_front({0, 0});

    int k;
    cin >> k;
    while(k--){
        int i, j;
        cin >> i >> j;
        grid[i-1][j-1] = 1;
    }

    int l;
    cin >> l;
    
    while(l--){
        int t;
        char d;
        cin >> t >> d;
        q.push({t, d});
    }

    int ans = 0;
    while(true){
        ans++;
        if(Move())
            break;

        if(!q.empty() && q.front().first == ans){
            int d = q.front().second;
            if(d=='D')
                dir = (dir+1)%4;
            else
                dir = (dir+3)%4;
            q.pop();
        }
    }

    cout << ans << '\n';
}