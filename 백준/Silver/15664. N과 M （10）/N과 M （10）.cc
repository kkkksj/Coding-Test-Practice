#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, m;
set<vector<int>> ans_set;

void Combi(vector<int> &arr, vector<int> &ans, int idx){
    if((int)ans.size() == m)
        ans_set.insert(ans);
    else{
        for(int i=idx+1; i<n; i++){
            ans.push_back(arr[i]);
            Combi(arr, ans, i);
            ans.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<int> ans;
    Combi(arr, ans, -1);
    
    for(vector<int> tmp_list : ans_set){
        for(int ans : tmp_list)
            cout << ans << ' ';
        cout << '\n';    
    }
}