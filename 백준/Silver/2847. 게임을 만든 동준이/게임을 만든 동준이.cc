#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int ans = 0;
    for(int i=n-1; i>0; i--){
        if(arr[i] <= arr[i-1]){
            ans += (arr[i-1] - (arr[i] - 1));
            arr[i-1] = arr[i]-1;
        }
    }

    cout << ans << '\n';
}