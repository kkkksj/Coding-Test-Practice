#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    set<int> set_arr;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr[i] = num;
        set_arr.insert(num);
    }
    vector<int> sorted(set_arr.begin(), set_arr.end());

    for(int num : arr){
        auto it = lower_bound(sorted.begin(), sorted.end(), num);
        int idx = distance(sorted.begin(), it);

        cout << idx << ' ';
    }
}