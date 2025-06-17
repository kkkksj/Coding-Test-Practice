#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() { 
    int n, k;
    cin >> n >> k;

    vector<int> coins (n);
    for(int i=n-1; i>-1; i--)
        cin >> coins[i];

    int ans = 0;
    for(int won : coins){
        if(won <= k){
            int r = k/won;
            k = k - (won * r);
            ans += r;
        }
        if(k == 0)
            break;
    }
    cout << ans << '\n';
}