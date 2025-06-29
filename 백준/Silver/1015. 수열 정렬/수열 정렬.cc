#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    vector<int> arr_copy(arr.begin(), arr.end());
    sort(arr_copy.begin(), arr_copy.end());

    for(int tmp : arr){
        auto idx = distance(arr_copy.begin(), find(arr_copy.begin(), arr_copy.end(), tmp));
        cout << idx << ' ';
        arr_copy[idx] = -1;
    }
}