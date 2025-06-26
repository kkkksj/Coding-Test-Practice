#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> list (n);
    for(int i=0; i<n; i++)
        cin >> list[i];
    
    int ans = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++)
            if(list[i] + list[j] == m)
                ans++;
    }

    cout << ans << '\n';
}