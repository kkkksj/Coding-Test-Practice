#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<string> list;
    string word;
    for(int i=0; i<n; i++){
        cin >> word;
        list.insert(word);
    }

    int ans = 0;
    for(int i=0; i<m; i++){
        cin >> word;
        auto idx = list.find(word);
        if(idx != list.end())
            ans++;
    }
    
    cout << ans << '\n';
}