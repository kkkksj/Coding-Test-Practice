#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> dist (n-1);
    vector<int> price (n);
    for(int i=0; i<n-1; i++)
        cin >> dist[i];
    for(int i=0; i<n; i++)
        cin >> price[i];

    int ans = 0;
    int dist_idx = 0;
    int price_idx= 0;
    while(dist_idx < n-1 && price_idx < n){
        ans += price[price_idx] * dist[dist_idx];
        if(price[price_idx] > price[price_idx+1])
            price_idx++;
        dist_idx++;
    }

    cout << ans << '\n';
}