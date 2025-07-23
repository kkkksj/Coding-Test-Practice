#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int ans = -1;
int n;
void Combi(vector<int> &ans_arr, vector<int> &arr, vector<int> &idx_list){
    if((int)ans_arr.size() == n){
        int sum = 0;
        for(int i=1; i<n; i++)
            sum += abs(ans_arr[i-1]-ans_arr[i]);
        ans = max(sum , ans);
    }
    else
        for(int i=0; i<n; i++)
            if(find(idx_list.begin(), idx_list.end(), i) == idx_list.end()){
                ans_arr.push_back(arr[i]);
                idx_list.push_back(i);
                Combi(ans_arr, arr, idx_list);
                ans_arr.pop_back();
                idx_list.pop_back();
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    vector<int> ans_arr;
    vector<int> idx_list;
    Combi(ans_arr, arr, idx_list);
    
    cout << ans << '\n';
}