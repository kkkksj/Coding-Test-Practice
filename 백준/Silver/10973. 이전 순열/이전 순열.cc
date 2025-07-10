#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int Find(vector<int> &ans, int n){
    for(int i=n-1; i>0; i--)
        if(ans[i] < ans[i-1])
            for(int j=n-1; j>=i; j--)
                if(ans[j] < ans[i-1]){
                    swap(ans[i-1], ans[j]);
                    return i;
                }
    return -1;
}

bool re(int a, int b){
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> ans (n);

    for(int i=0; i<n; i++)
        cin >> ans[i];
    
    int idx = Find(ans, n);
    if(idx == -1)
        cout << -1;
    else{
        vector<int> part (ans.begin()+idx, ans.end());
        sort(part.begin(), part.end(), re);
        for(int i=0; i<idx; i++)
            cout << ans [i] << ' ';
        for(int tmp : part)
            cout << tmp << ' ';
    }
}