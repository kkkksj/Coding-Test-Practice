#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr (n+1);
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for(int i=4; i<n+1; i++){
        if(i%6 == 0)
            arr[i] = min(arr[i/3], min(arr[i/2], arr[i-1])) + 1;
        else if(i%3 == 0)
            arr[i] = min(arr[i/3], arr[i-1]) + 1;
        else if(i%2== 0)
            arr[i] = min(arr[i/2], arr[i-1]) + 1;
        else
            arr[i] = arr[i-1] + 1;
    }

    cout << arr[n] << '\n';
}