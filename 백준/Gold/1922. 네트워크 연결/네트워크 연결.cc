#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;

vector<int> parent;

int FindParent(int a){
    if(parent[a] == a)
        return a;
    return parent[a] = FindParent(parent[a]);
}

void Connect(int a, int b){
    int pa = FindParent(a);
    int pb = FindParent(b);

    parent[pb] = pa;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<pair<int, pair<int, int>>> connected;

    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        connected.push_back({w, {a, b}});
    }

    sort(connected.begin(), connected.end());

    parent.assign(n+1, 0);
    for(int i=1; i<n+1; i++)
        parent[i] = i;

    int u = 0;
    int ans = 0;
    for(int i=0; i<(int)connected.size(); i++){
        int w = connected[i].first;
        int a = connected[i].second.first;
        int b = connected[i].second.second;

        if(FindParent(a) == FindParent(b))
            continue;
        
        Connect(a, b);
        u++;
        ans += w;

        if(u == n)
            break;
    }

    cout << ans << '\n';
}