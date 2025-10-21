#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> jump (101, -1);

int BFS(){
    vector<bool> visited (101, false);
    queue<pair<int, int>> q;
    q.push({1, 0});

    while(!q.empty()){
        int now_num = q.front().first;
        int now_cnt = q.front().second;
        q.pop();

        if(now_num == 100)
            return now_cnt;

        for(int i=1; i<7; i++){
            int next_num = now_num + i;
            if(next_num > 100 )
                continue;
            if(jump[next_num] != -1)
                next_num = jump[next_num];
            if(visited[next_num])
                continue;
            
            visited[next_num] = true;
            q.push({next_num, now_cnt+1});
        }
    }
    
    return -1;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n+m; i++){
        int a, b;
        cin >> a >> b;

        jump[a] = b;
    }

    cout << BFS() << '\n';
}   