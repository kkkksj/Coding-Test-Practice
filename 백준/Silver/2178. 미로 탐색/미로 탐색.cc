#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct Pos {
    int x;
    int y;
};

int BFS(vector<string> &maze){
    queue<Pos> q;
    q.push({0,0});

    vector<int> x_list = {-1, 0, 1, 0};
    vector<int> y_list = {0, -1, 0, 1};
    vector<vector<int>> dist (n, vector<int> (m, 0));
    dist[0][0] = 1;
    while(!q.empty()){
        Pos now = q.front();
        int now_x = now.x;
        int now_y = now.y;
        q.pop();

        for(int i=0; i<4; i++){
            int next_x = now_x + x_list[i];
            int next_y = now_y + y_list[i];

            if((next_x >= 0 && next_x < m) && (next_y >= 0 && next_y < n))
                if(maze[next_y][next_x] == '1' && dist[next_y][next_x] == 0){
                    q.push({next_x, next_y});
                    dist[next_y][next_x] = dist[now_y][now_x] + 1;
                    if(next_x == n-1 && next_y == m-1)
                        return dist[next_y][next_x];
                }
        }
    }

    return dist[n-1][m-1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    
    vector<string> maze(n);
    for(int i=0; i<n; i++)
        cin >> maze[i];
    
    cout << BFS(maze) << '\n';
}