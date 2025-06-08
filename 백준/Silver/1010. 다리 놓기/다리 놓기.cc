#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    for(int c=0; c<t; c++){
        long long ans=1;
        cin >> m >> n;
        for(int i=n; i>(n-m); i--){
            ans = ans * i;
            ans = ans / (n+1-i);
        }
        if(m==0)
            cout << 0 << '\n';
        else
            cout << ans << '\n';
    }
}