#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    vector<int> dp1(n, 1);
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i])
                dp1[i] = max(dp1[j]+1, dp1[i]);
        }
    vector<int> dp2(n, 1);
    for(int i=n-2; i>=0; i--)
        for(int j=n-1; j>i; j--){
            if(arr[j] < arr[i])
                dp2[i] = max(dp2[j]+1, dp2[i]);
        }
    
    int ans = 0;
    for(int i=0; i<n; i++)
        ans = max(ans, dp1[i]+dp2[i]-1);

    cout << ans << '\n';
}