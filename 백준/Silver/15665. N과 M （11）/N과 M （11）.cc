#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<vector<int>> ans_set;
int n, m;
void Combi(vector<int> &arr, vector<int> &ans){
    if((int)ans.size() == m)
        ans_set.insert(ans);
    else
        for(int tmp:arr){
            ans.push_back(tmp);
            Combi(arr, ans);
            ans.pop_back();
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
    Combi(arr, ans);
    
    for(vector<int> ansvec : ans_set){
        for(int ans : ansvec)
            cout << ans << ' ';
        cout << '\n';
    }
}