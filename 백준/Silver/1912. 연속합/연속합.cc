#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> sum_list (n+1, 0);
    for(int i=1; i<n+1; i++){
        cin >> sum_list[i];
        sum_list[i] += sum_list[i-1];
    }

    int ans = -1000000001;
    int min_n = 0;
    for(int i=1; i<n+1; i++){
        ans = max(sum_list[i]-min_n, ans);
        min_n = min(min_n, sum_list[i]);
    }
    
    cout << ans << '\n';
}