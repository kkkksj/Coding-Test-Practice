#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> grdae (n, vector<int> (2));
        for(int i=0; i<n; i++)
            cin >> grdae[i][0] >> grdae[i][1];
        
        sort(grdae.begin(), grdae.end());
        int standard = grdae[0][1];
        int ans = 1;
        for(int i=1; i<n; i++)
            if(grdae[i][1] < standard){
                standard = grdae[i][1];
                ans++;
            }
        
        cout << ans << '\n';
    }
}