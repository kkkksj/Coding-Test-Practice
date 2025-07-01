#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n+1, 0);
    for(int i=1; i<n+1; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    
    int s, e;
    for(int i=0; i<m; i++){
        cin >> s >> e;
        cout << arr[e]-arr[s-1] << '\n';
    }
}