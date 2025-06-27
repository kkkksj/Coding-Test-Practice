#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 0)
        cout << 0 << '\n';
    
    else {
        vector<float> arr (n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        int except = round((n*15)/100.);
        float ans = 0;
        int cnt = 0;
        for(int i=except; i<n-except; i++){
            ans += arr[i];
            cnt++;
        }

        cout << round(ans/cnt) << '\n';
    }
}