#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Search(vector<vector<int>> &landsea, int idx, int jdx, int w, int h){
    if(landsea[idx][jdx] == 0)
        return;
    landsea[idx][jdx] = 0;
    vector<int> jdx_list = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> idx_list = {0, 1, -1, 1, -1, 0, 1, -1};
    for(int p=0; p<8; p++){
        int next_i = idx+idx_list[p];
        int next_j = jdx+jdx_list[p];
        if(next_i>=0 && next_i<h && next_j>=0 && next_j<w)
            Search(landsea, next_i, next_j, w, h);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int w, h;
    while(1){
        cin >> w >> h;
        if(w==0 && h==0)
            break;
        vector<vector<int>> landsea (h, vector<int> (w));
        int ans = 0;
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                cin >> landsea[i][j];
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                if(landsea[i][j] == 1){
                    Search(landsea, i, j, w, h);
                    ans++;
                }
        cout << ans << '\n';
    }
}