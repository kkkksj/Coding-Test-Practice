#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n, m;

void Combi(vector<int> &arr, vector<int> &ans, set<vector<int>> &ans_set, vector<int> idx_list){
    if((int)ans.size() == m)
        ans_set.insert(ans);
    
    else
        for(int i=0; i<n; i++)
            if(find(idx_list.begin(), idx_list.end(), i) == idx_list.end()){
                ans.push_back(arr[i]);
                idx_list.push_back(i);
                Combi(arr, ans, ans_set, idx_list);
                ans.pop_back();
                idx_list.pop_back();
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
    set<vector<int>> ans_set;
    vector<int> idx_list;
    Combi(arr, ans, ans_set, idx_list);

    for(vector<int> tmp_vec : ans_set){
        for(int tmp : tmp_vec)
            cout << tmp << ' ';
        cout << '\n';
    }
}