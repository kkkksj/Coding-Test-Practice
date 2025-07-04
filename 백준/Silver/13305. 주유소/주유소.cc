#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<long long> dist (n-1);
    vector<long long> price (n);
    for(int i=0; i<n-1; i++)
        cin >> dist[i];
    for(int i=0; i<n; i++)
        cin >> price[i];

    long long ans = 0;
    int price_idx = 0;
    for(int i=0; i<n-1; i++){
        if(price[price_idx] > price[i])
            price_idx = i;
        ans += (price[price_idx] * dist[i]);
    }

    cout << ans << '\n';
}