#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

bool CMP(pair<int, int> a, pair<int, int>b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;
    map<int, int> map_arr;
    vector<int> arr (n);
    int num;
    int min_n = 4000;
    int max_n = -4000;
    for(int i=0; i<n; i++){
        cin >> num;
        arr[i] = num;
        map_arr[num]++;
        min_n = min(min_n, num);
        max_n = max(max_n, num);
        sum += num;
    }

    vector<pair<int, int>> vec_map (map_arr.begin(), map_arr.end());

    sort(vec_map.begin(), vec_map.end(), CMP);
    sort(arr.begin(), arr.end());

    cout << floor(sum/(double)n + 0.5) << '\n';
    cout << arr[n/2] << '\n';
    if(vec_map[0].second != vec_map[1].second)
        cout << vec_map[0].first << '\n';
    else
        cout << vec_map[1].first << '\n';
    cout << max_n-min_n << '\n';
}