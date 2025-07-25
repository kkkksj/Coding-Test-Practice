#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n+1, 1);
    for(int i=2; i<n+1; i++)
        arr[i] = (arr[i-1] + arr[i-2])%10007;
    
    cout << arr[n] << '\n';
    cout.flush();
}