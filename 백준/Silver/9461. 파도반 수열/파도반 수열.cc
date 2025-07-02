#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int c=0; c<t; c++){
        int n;
        cin >> n;

        vector<long long> arr(n+1, 0);
        arr[1] = 1;
        if(n > 1)
            arr[2] = 1;
        for(int i=3; i<n+1; i++)
            arr[i] = arr[i-2] + arr[i-3];
        
        cout << arr[n] << '\n';
    }
}