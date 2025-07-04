#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Combi(vector<int> arr, vector<int> &ans, int m, int n){
    if(int(ans.size()) == m){
        for(int num : ans)
            cout << num << ' ';
        cout << '\n';
    }
    else
        for(int num : arr)
            if(ans.empty() || *ans.rbegin() <= num){
                ans.push_back(num);
                Combi(arr, ans, m, n);
                ans.pop_back();
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    vector<int> ans;
    Combi(arr, ans, m, n);
}