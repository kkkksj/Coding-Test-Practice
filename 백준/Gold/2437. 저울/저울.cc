#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int n;
vector<int> arr;
 
int main() {
    cin >> n;
    
    arr.assign(n, 0);
    
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
     sort(arr.begin(), arr.end());
    
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > ans)
            break;
        ans += arr[i];
    }
 
    cout << ans << '\n';
}