#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

int n, m;

int Make(vector<vector<int>> &land, int h, int b){
    int ttime = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(land[i][j] > h)
                for(int k=0; k<land[i][j]-h; k++){
                    ttime += 2;
                    b++;
                }
            else if(land[i][j] < h)
                for(int k=0; k<h-land[i][j]; k++){
                    ttime += 1;
                    b--;
                }
            }
    if(b<0)
        return INT_MAX;
    return ttime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int b;
    cin >> n >> m >> b;

    vector<vector<int>> land(n, vector<int> (m));
    int max_h = 0;
    int min_h = 256;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> land[i][j];
            max_h = max(max_h, land[i][j]);
            min_h = min(min_h, land[i][j]);
        }
    
    int ans_h = max_h;
    int ans_t = INT_MAX;
    for(int h=max_h; h>=min_h; h--){
        int t = Make(land, h, b);
        if(t < ans_t){
            ans_t = t;
            ans_h = h;
        }
        else if(t == ans_t)
            if(ans_h < h)
                ans_h = h;
    }

    cout << ans_t << ' ' << ans_h << '\n';
}