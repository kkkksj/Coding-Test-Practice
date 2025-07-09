#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int find(vector<int> ans, int n){
    int idx = n-1;
    while(idx > 0){
        if(ans[idx] > ans[idx-1])
            return idx;
        idx --;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> ans(n);
    for(int i=0; i<n; i++)
        cin >> ans[i];
    
    int idx = find(ans, n);
    if(idx == -1)
        cout << -1 << '\n';
    else{
        int jdx = n-1;
        while(jdx > 0){
            if(ans[jdx] > ans[idx-1])
                break;
            jdx--;
        }
        swap(ans[idx-1], ans[jdx]);
        vector<int> tmp (ans.begin()+idx, ans.end());
        sort(tmp.begin(), tmp.end());
        for(int i=0; i<idx; i++)
            cout << ans[i] << ' ';
        for(int num : tmp)
            cout << num << ' ';
    }
}