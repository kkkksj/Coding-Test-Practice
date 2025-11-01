#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> ans;
vector<bool> visited;
vector<int> arr;

void DFS(int start, int node){
    if(visited[node]){
        if(start==node)
            ans.push_back(node);
        return;
    }
    visited[node] = true;
    DFS(start, arr[node]);
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;

    arr.assign(n+1, 0);
    for(int i=1; i<n+1; i++)
        cin >> arr[i];
    
    for(int i=1; i<n+1; i++){
        visited.assign(n+1, false);
        DFS(i, i);
    }

    cout << ans.size() << '\n';
    for(int x : ans)
        cout << x << '\n';
}