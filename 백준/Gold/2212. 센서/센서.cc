#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<int> gap(n-1);
    for(int i=1; i<n; i++)
        gap[i-1] = arr[i]-arr[i-1];
    
    sort(gap.begin(), gap.end(), greater<int>());
    int answer = 0;

    for(int i=k-1; i<n-1; i++)
        answer += gap[i];
        
    cout << answer << '\n';
}