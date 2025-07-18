#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Combi(vector<int> &arr, vector<int> &ans){
    if(ans.size() == 6){
        for(int n : ans)
            cout << n << ' ';
        cout << '\n';
    }
    else
        for(int n : arr)
            if(ans.empty() || *ans.rbegin() < n){
                ans.push_back(n);
                Combi(arr, ans);
                ans.pop_back();
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int k;
    vector<int> ans;
    while(true){
        cin >> k;
        
        if(k==0)
            break;
        
        vector<int> arr(k);
        for(int i=0; i<k; i++)
            cin >> arr[i];
        
        ans.clear();
        Combi(arr, ans);
        cout << '\n';
    }
}