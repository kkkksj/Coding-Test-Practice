#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int find(int m, int n, int x, int y) {
    if (m == x) 
        x = 0;
    if (n == y) 
        y = 0;
    for (int i = x; i <= m * n; i += m) {
        if (i == 0) 
            continue;
        if (i % n == y) 
            return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;

    while(t--){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        
        cout << find(m, n, x, y) << '\n';
    }
}