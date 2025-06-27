#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int GCD(int a, int b){
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> gap (n-1);
    int pretree;
    int tree;
    for(int i=0; i<n; i++){
        cin >> tree;
        if(i == 0)
            pretree = tree;
        else{
            gap[i-1] = tree - pretree;
            pretree = tree;
        }
    }

    int gcd = gap[0];
    for(int i=1; i<n-1; i++){
        gcd = GCD(gcd, gap[i]);
    }

    int ans = 0;
    for(int i=0; i<n-1; i++){
        ans += (gap[i]/gcd - 1);
    }
    
    cout << ans << '\n';
}