#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> times(n);
    for(int i=0; i<n; i++)
        cin >> times[i].first >> times[i].second;
        
    sort(times.begin(), times.end(), cmp);

    int end_time = times[0].second;
    int ans = 1;
    for(int i=1; i<n; i++){
        if(times[i].first >= end_time){
            end_time = times[i].second;
            ans++;
        }
    }

    cout << ans << '\n';
}
