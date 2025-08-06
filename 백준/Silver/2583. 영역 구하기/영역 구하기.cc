#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct POINT{
    int i;
    int j;
};

int BFS(vector<vector<bool>> &rectangle, int i, int j){
    rectangle[i][j] = true;

    queue<POINT> q;
    q.push({i, j});

    vector<int> i_list = {-1, 0, 1, 0};
    vector<int> j_list = {0, -1, 0, 1};
    int ret = 0;
    while(!q.empty()){
        int now_i = q.front().i;
        int now_j = q.front().j;
        ret++;
        q.pop();

        for(int i=0; i<4; i++){
            int next_i = now_i + i_list[i];
            int next_j = now_j + j_list[i];
            if((next_i>=0 && next_i<n) && (next_j>=0 && next_j<m))
                if(rectangle[next_i][next_j] == false){
                    q.push({next_i, next_j});
                    rectangle[next_i][next_j] = true; 
                }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k;
    cin >> n >> m >> k;

    vector<vector<bool>> rectangle(n, vector<bool> (m));
    int sx, sy, ex, ey;
    while(k--){
        cin >> sx >> sy >> ex >> ey;
        for(int i=sy; i<ey; i++)
            for(int j=sx; j<ex; j++)
                rectangle[i][j] = true;
    }

    vector<int> ans;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(rectangle[i][j] == false)
                ans.push_back(BFS(rectangle, i, j));
       
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int a:ans)
        cout << a << ' ';
}