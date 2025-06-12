#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() { 
    int n, m;
    cin >> n >> m;

    vector<int> arr1 (n+m, 0);
    for(int i=0; i<n+m; i++)
        cin >> arr1[i];
    sort(arr1.begin(), arr1.end());
    for(int i=0; i<n+m; i++)
        cout << arr1[i] << ' ';
}