#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, l;
    cin >> n >> l;

    vector<int> point (n);
    for(int i=0; i<n; i++)
        cin >> point[i];

    sort(point.begin(), point.end());

    int i = 0;
    float len = point[0]-0.5 + l;
    int ans = 1;
    while(i<n){
        if(len >= point[i]+0.5)
            i++;
        else{
            ans++;
            len = point[i++] - 0.5 + l;
        }
    }
    
    cout << ans << '\n';    
}