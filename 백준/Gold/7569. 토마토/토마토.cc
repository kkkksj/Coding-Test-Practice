#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m, n ,h;
vector<vector<int>> tomatos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n >> h;

    tomatos.resize(n*h, vector<int> (m));
    queue<pair<int, int>> q;
    int ttmato = 0;
    for(int i=0; i<n*h; i++)
        for(int j=0; j<m; j++){
            int t;
            cin >> t;
            tomatos[i][j] = t;
            if(t == 1 || t == 0){
                ttmato++;
                if(t==1)
                    q.push({i, j});
            }
        }
    
    vector<int> i_list = {-1, 0, 1, 0, -n, n};
    vector<int> j_list = {0, -1, 0, 1, 0, 0};
    int day = 0;
    int cnt = 0;
    while(!q.empty()){
        int now_i = q.front().first;
        int now_j = q.front().second;
        q.pop();
        day = max(day, tomatos[now_i][now_j]);
        cnt++;

        for(int dir=0; dir<6; dir++){
            if((dir == 0 && (now_i+1)%n==1) || (dir == 2 && (now_i+1)%n==0))
                continue;
            int next_i = now_i + i_list[dir];
            int next_j = now_j + j_list[dir];

            if((next_i>=0 && next_i<n*h) && (next_j>=0 && next_j<m))
                if(tomatos[next_i][next_j] == 0){
                    tomatos[next_i][next_j] = tomatos[now_i][now_j]+1;
                    q.push({next_i, next_j});
                }
        }
    }

    if(cnt == ttmato)
        cout << day-1 << '\n';
    else
        cout << -1 << '\n';
}