#include <iostream>
#include <algorithm>
#include <deque>
#include <unordered_map>
using namespace std;

void Combi(deque<int> &ans, int n, int m){
    if((int)ans.size() == m){
        for(int num : ans)
            cout << num << ' ';
        cout << '\n';
    }
    else
        for(int i=1; i<n+1; i++){
            ans.push_back(i);
            Combi(ans, n, m);
            ans.pop_back();
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    deque<int> ans;
    Combi(ans, n, m);
}