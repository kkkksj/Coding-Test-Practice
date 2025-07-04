#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> temp (n+1, 0);
    int temperature;
    for(int i=1; i<n+1; i++){
        cin >> temperature;
        temp[i] = temp[i-1] + temperature;
    }

    int max_temp = -100*n;
    for(int i=k; i<n+1; i++)
        max_temp = max(max_temp, temp[i]-temp[i-k]);

    cout << max_temp << '\n';
}