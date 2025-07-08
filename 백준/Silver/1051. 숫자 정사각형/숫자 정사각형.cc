#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int FindSquare(vector<string> arr, int n, int m, int idx, int jdx){
    int target = arr[idx][jdx];
    int max_area = 0;
    for(int i=jdx+1; i<jdx+n-idx && i<m; i++){
        if(arr[idx][i] == target && arr[idx+(i-jdx)][jdx] == target && arr[idx+(i-jdx)][i] == target)
            max_area = max(max_area, (i-jdx+1)*(i-jdx+1));
    }
    return max_area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int ans = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans = max(ans, FindSquare(arr, n, m, i, j));
        }
    }
    cout << ans << '\n';
}