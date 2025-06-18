#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool IsThere(vector<signed int> &arr, signed int num, int n){
    int s = 0;
    int e = n - 1;
    int mid;
    while(s <= e){
        mid = (s+e)/2;
        if(arr[mid] == num)
            return 1;
        else if(arr[mid] < num)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return 0;
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n;

    vector<signed int> arr (n);
    signed int num;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> num;
        if(IsThere(arr, num, n))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}