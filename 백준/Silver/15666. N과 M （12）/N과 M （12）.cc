#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

set<vector<int>> ans_set;
int n, m;
void Combi(vector<int> &ans, vector<int> &arr){
    if((int)ans.size() == m)
        ans_set.insert(ans);
    else
        for(int tmp : arr)
            if(ans.empty() || *ans.rbegin() <= tmp){
                ans.push_back(tmp);
                Combi(ans, arr);
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
    Combi(ans, arr);

    for(vector<int> tmp_vec : ans_set){
        for(int tmp : tmp_vec)
            cout << tmp << ' ';
        cout << '\n';
    }
}