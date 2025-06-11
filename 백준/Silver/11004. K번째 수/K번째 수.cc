#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, k;
    cin >> n >> k;
    
    vector<long long> arr (n, 0);
    for(long long i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    cout << arr[k-1] << '\n';
}