#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Combi(vector<int> arr, vector<int> &ans, int n, int m){
    if((int)ans.size() == m){
        for(int tmp : ans)
            cout << tmp << ' ';
        cout << '\n';
    }
    else
        for(int tmp : arr){
            ans.push_back(tmp);
            Combi(arr, ans, n, m);
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
    Combi(arr, ans, n, m);
}