#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> tomatos;
vector<vector<int>> day;
int m, n;
vector<int> i_list = {-1, 0, 1, 0};
vector<int> j_list = {0, -1, 0, 1};

int BFS(queue<pair<int, int>> q, int ttmato){
    int cnt = 0;
    int day_cnt = 0;

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        cnt++;

        for(int dir=0; dir<4; dir++){
            int next_i = i + i_list[dir];
            int next_j = j + j_list[dir];

            if((next_i>=0 && next_i<n) && (next_j>=0 && next_j<m))
                if(tomatos[next_i][next_j] == 0){
                    tomatos[next_i][next_j] = 1;
                    q.push({next_i, next_j});
                    day[next_i][next_j] = day[i][j] + 1;
                    day_cnt = max(day[next_i][next_j], day_cnt);
                }
        }
    }

    if(ttmato == cnt)
        return day_cnt;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;

    tomatos.resize(n, vector<int> (m));
    day.resize(n, vector<int> (m, -1));
    queue<pair<int, int>> q;
    int ttomato = 0; 
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            int t;
            cin >> t;
            tomatos[i][j] = t;
            
            if(t==0 || t==1){
                ttomato++;
                if(t==1){
                    q.push({i, j});
                    day[i][j] = 0;
                }
            }
        }
    
    cout << BFS(q, ttomato) << '\n';
}
