#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> friends;
bool ans_flag = false;

void DFS(vector<int> &abcde, int now){
    if(abcde.size() == 5){
        cout << 1 << '\n';
        ans_flag = true;
        return;
    }
    else{
        for(int next:friends[now]){
            if(find(abcde.begin(), abcde.end(), next)==abcde.end()){
                abcde.push_back(next);
                DFS(abcde, next);
                if(ans_flag)
                    return;
                abcde.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    friends.resize(n, vector<int> ());

    while(m--){
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        vector<int> abcde = {i};
        DFS(abcde, i);
        if(ans_flag)
            break;
    }
    if(!ans_flag)
        cout << 0 << '\n';
}