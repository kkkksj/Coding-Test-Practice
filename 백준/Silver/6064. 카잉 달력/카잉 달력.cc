#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int find(int m, int n, int x, int y){
    unordered_set<int> s;
    for(int i=0; i<40000; i++){
        int rest = (i*m + x)%n;
        if(rest == 0)
            rest = n;
        if(rest == y)
            return i*m + x;
        if(s.find(rest) != s.end())
            return -1;
        s.insert(rest);
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