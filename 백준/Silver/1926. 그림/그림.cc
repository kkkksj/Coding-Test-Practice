#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> i_list = {-1, 0, 1, 0};
vector<int> j_list = {0, -1, 0, 1};

struct POINT{
    int i;
    int j;
};

int BFS(vector<vector<int>> &picture, int i, int j){
    queue<POINT> q;
    q.push({i, j});

    picture[i][j] = 0;
    int ret = 0;
    while(!q.empty()){
        int now_i = q.front().i;
        int now_j = q.front().j;
        q.pop();
        ret++;

        for(int i=0; i<4; i++){
            int next_i = now_i + i_list[i];
            int next_j = now_j + j_list[i]; 

            if((next_i>=0 && next_i<n) && (next_j>=0 && next_j<m))
                if(picture[next_i][next_j] == 1){
                    picture[next_i][next_j] = 0;
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
    vector<vector<int>> picture (n, vector<int> (m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> picture[i][j];
    
    int ans_num = 0;
    int ans_area = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(picture[i][j] == 1){
                ans_area = max(ans_area, BFS(picture, i, j));
                ans_num++;
            }
    
    cout << ans_num << '\n' << ans_area << '\n';
}