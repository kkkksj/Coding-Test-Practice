#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool OutorIn(int x, int y, int cx, int cy, int r){
    if((pow(x-cx, 2) + pow(y-cy, 2)) <= pow(r, 2))
        return 1;   //inside
    return 0;   //outside
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for(int j=0; j<t; j++){  
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        
        int n;
        cin >> n;

        int cx, cy, r;
        int ans = 0;
        for(int i=0; i<n; i++){
            cin >> cx >> cy >> r;
            if((OutorIn(sx, sy, cx, cy, r) && !OutorIn(ex, ey, cx, cy, r)) || (!OutorIn(sx, sy, cx, cy, r) && OutorIn(ex, ey, cx, cy, r)))
                ans++;
        }
        cout << ans << '\n';
    }
}