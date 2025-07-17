#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

void Back(vector<int> arr, vector<int> &ans_list, int &ans, int m, int s, int n, int idx){
    if((int)ans_list.size() == m){
        int ans_sum = 0;
        for(int tmp : ans_list)
            ans_sum += tmp;
        if(ans_sum == s)
            ans++;
    }
    else
        for(int i=0; i<n; i++)
            if(ans_list.empty() || idx < i){
                ans_list.push_back(arr[i]);
                Back(arr, ans_list, ans, m, s, n, i);
                ans_list.pop_back();
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    int ans = 0;
    vector<int> ans_list;
    for(int i=1; i<n+1; i++){
        ans_list.clear();
        Back(arr, ans_list, ans, i, s, n, -1);
    }
    cout << ans << '\n';
}