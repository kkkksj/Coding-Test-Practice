#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Combi(vector<int> list, vector<int> &ans, int m){
    if((int)ans.size() == m){
        for(int num : ans)
            cout << num << ' ';
        cout << '\n';
    }
    else
        for(int num : list)
            if(find(ans.begin(), ans.end(), num) == ans.end()){
                ans.push_back(num);
                Combi(list, ans, m);
                ans.pop_back();
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> list (n);
    for(int i=0; i<n; i++)
        cin >> list[i];

    sort(list.begin(), list.end());
    vector<int> ans;
    Combi(list, ans, m);
}