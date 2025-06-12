#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() { 
    int n, m;
    cin >> n >> m;

    vector<int> arr1 (n, 0);
    vector<int> arr2 (m, 0);
    vector<int> ans (m+n, 0);
    for(int i=0; i<n; i++)
        cin >> arr1[i];
    for(int i=0; i<m; i++)
        cin >> arr2[i];
    
    int idx1 = 0, idx2 = 0, i = 0;
    while(i < n+m){
        if(idx1 == n){
            ans[i] = arr2[idx2];
            idx2++;
        }
        else if(idx2 == m){
            ans[i] = arr1[idx1];
            idx1++;
        }
        else{
            if(arr1[idx1] <= arr2[idx2]){
                ans[i] = arr1[idx1];
                idx1++;
            }
            else{
                ans[i] = arr2[idx2];
                idx2++;
            }
        }
        i++;
    }
    for(int i=0; i<n+m; i++)
        cout << ans[i] << ' ';
}