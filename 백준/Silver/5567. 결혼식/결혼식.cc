#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> friends (n+1);
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    unordered_set<int> ans (friends[1].begin(), friends[1].end());
    for(int num : friends[1])
        for(int ffreind : friends[num])
            if(ffreind != 1)    
                ans.insert(ffreind);
    
    cout << ans.size() << '\n';
}