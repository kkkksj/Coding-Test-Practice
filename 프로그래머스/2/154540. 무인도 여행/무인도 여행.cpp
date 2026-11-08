#include <string>
#include <vector>
#include <queue>

#define MAXN 100

using namespace std;

int n, m;
int i_list[4] = {-1, 1, 0, 0};
int j_list[4] = {0, 0, -1, 1};
bool visited[MAXN+1][MAXN+1];

struct Pos{
    int i, j;  
};

int BFS(vector<string> maps, int i, int j){
    queue<Pos> q;
    q.push({i, j});
    int ret = maps[i][j]-'0';
    visited[i][j] = true;
    
    while(!q.empty()){
        Pos now = q.front();
        q.pop();
        
        for(int d=0; d<4; d++){
            int nexti = now.i + i_list[d];
            int nextj = now.j + j_list[d];
            
            if(nexti<0 || nexti>=n || nextj<0 || nextj>=m)
                continue;
            if(maps[nexti][nextj] == 'X' || visited[nexti][nextj])
                continue;
            
            ret += maps[nexti][nextj] - '0';
            visited[nexti][nextj] = true;
            q.push({nexti, nextj});
        }
    }
    
    return ret;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size();
    m = maps[0].size();
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(visited[i][j] || maps[i][j] == 'X')
                continue;
            
            pq.push(BFS(maps, i, j));
        }
    
    if(pq.size() == 0){
        answer.push_back(-1);
        return answer;
    }
    while(!pq.empty()){
        answer.push_back(pq.top());
        pq.pop();
    }
    return answer;
}