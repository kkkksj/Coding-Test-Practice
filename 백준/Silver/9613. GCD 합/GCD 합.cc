#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int GCD(int a, int b){
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

int main() {
    int t;
    cin >> t;
    
    int n;
    for(int i=0; i<t; i++){
        cin >> n;
        vector<int> arr (n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        long long ans = 0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                ans += GCD(arr[i], arr[j]);
        cout << ans << '\n';
    }
}