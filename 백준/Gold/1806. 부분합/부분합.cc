#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> arr(n, 0);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int i = 0, j = 0;
    int psum = arr[0];
    int ans = n+1;

    while(i<=j && j<n){
        if(psum < s){
            j++;
            psum += arr[j];
        }
        else{
            ans = min(ans, j-i+1);
            psum -= arr[i];
            i++;
        }
    }

    if(ans == n+1)
        ans = 0;
    cout << ans << '\n';
}