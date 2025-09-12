#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int FindParent(int a){    //부모 노드 찾기
    if(parent[a] == a)
        return a;
    return parent[a] = FindParent(parent[a]);
}

void Connect(int a, int b){    // 합치기 (부모 노드를 갖게 하기)
    int pa = FindParent(a);
    int pb = FindParent(b);

    parent[pb] = pa; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    vector<pair<int, pair<int, int>>> connected;
    while(e--){
        int a, b, w;
        cin >> a >> b >> w;
        connected.push_back({w, {a, b}});
    }

    sort(connected.begin(), connected.end());

    parent.assign(v+1, 0);
    for(int i=1; i<v+1; i++)
        parent[i] = i;  // 자기 자신으로 초기화

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

        if(u == v)
            break;
    } 

    cout << ans << '\n';
}