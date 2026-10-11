#include<vector>
#include<queue>

using namespace std;

int n, m;
int i_list[4] = {0, 0, -1, 1};
int j_list[4] = {-1, 1, 0, 0};

int BFS(vector<vector<int>> maps){
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, -1));
    
    q.push({0, 0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        if(now.first == n-1 && now.second == m-1)
            return visited[n-1][m-1];
        
        for(int d=0; d<4; d++){
            int next_i = now.first + i_list[d];
            int next_j = now.second + j_list[d];
            
            if(next_i < 0 || next_i >= n || next_j < 0 || next_j >= m)
                continue;
            if(visited[next_i][next_j] != -1 || maps[next_i][next_j] == 0)
                continue;
            
            visited[next_i][next_j] = visited[now.first][now.second] + 1;
            q.push({next_i, next_j});
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    n = maps.size();
    m = maps[0].size();
    
    answer = BFS(maps);
    return answer;
}