#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> i_list = {-1, 0, 1, 0};
vector<int> j_list = {0, -1, 0, 1};

void DFS(vector<string> &map_vec, int r, int c, int &num){
    map_vec[r][c] = '0';    //방문표시
    
    for(int i=0; i<4; i++){
        int next_r = r+i_list[i];
        int next_c = c+j_list[i];

        if((next_r >= 0 && next_r < n) && (next_c >= 0 && next_c < n))
            if(map_vec[next_r][next_c] == '1'){
                num++;
                DFS(map_vec, next_r, next_c, num);
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    vector<string> map_vec(n);
    for(int i=0; i<n; i++)
        cin >> map_vec[i];
    
    int ans = 0;
    vector<int> ans_vec;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(map_vec[i][j] == '1'){
                int num = 1;
                DFS(map_vec, i, j, num);
                ans++;
                ans_vec.push_back(num);
            }

    cout << ans << '\n';

    sort(ans_vec.begin(), ans_vec.end());
    for(int a : ans_vec)
        cout << a << '\n';
}