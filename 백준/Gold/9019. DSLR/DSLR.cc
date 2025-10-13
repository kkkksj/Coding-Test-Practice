#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t;
int start, goal;
vector<bool> visited;

string BFS(){
    visited[start] = true;
    queue<pair<int, string>> q;
    q.push({start, ""});

    while(!q.empty()){
        int now_int = q.front().first;
        string now_cmd = q.front().second;
        q.pop();

        if(now_int == goal)
            return now_cmd;
            
        int D, S, L, R;
        D = (now_int*2)%10000;
        if(!visited[D]){
            visited[D] = true;
            q.push({D, now_cmd+'D'});
        }

        S = now_int - 1;
        if(S == -1)
            S = 9999;
        if(!visited[S]){
            visited[S] = true;
            q.push({S, now_cmd+'S'});
        }

        L = (now_int*10)%10000 + now_int/1000;
        if(!visited[L]){
            visited[L] = true;
            q.push({L, now_cmd+'L'});
        }

        R = now_int/10 + (now_int%10)*1000;
        if(!visited[R]){
            visited[R] = true;
            q.push({R, now_cmd+'R'});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    
    while(t--){
        cin >> start >> goal;
        visited.assign(10000, false);
        cout << BFS() << '\n';
    }
}