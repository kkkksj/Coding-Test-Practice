#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct POINT{
    int i; 
    int j;
};

vector<int> i_list = {-1, 0, 1, 0};
vector<int> j_list = {0, -1, 0, 1};

void BFS(vector<vector<int>> &graph, vector<vector<int>> &dist, int goal_i, int goal_j){
    queue<POINT> q;
    q.push({goal_i, goal_j});

    while(!q.empty()){
        int now_i = q.front().i;
        int now_j = q.front().j;
        q.pop();
        
        for(int i=0; i<4; i++){
            int next_i = now_i + i_list[i];
            int next_j = now_j + j_list[i];

            if((next_i>=0 && next_i<n) && (next_j>=0 && next_j<m)){
                if(graph[next_i][next_j] == 0)
                    dist[next_i][next_j] = 0;
                else if(dist[next_i][next_j] == -1){
                    dist[next_i][next_j] = dist[now_i][now_j] + 1;
                    q.push({next_i, next_j});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;

    int goal_i, goal_j;
    vector<vector<int>> graph (n, vector<int> (m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 2){
                goal_i = i;
                goal_j = j;
            }    
        }
    
    vector<vector<int>> dist (n, vector<int> (m, -1));
    dist[goal_i][goal_j] = 0;
    BFS(graph, dist, goal_i, goal_j);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j] == 0)
                cout << 0 << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}