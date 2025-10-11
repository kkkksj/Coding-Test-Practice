#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> i_list = {-1, 1, 0, 0};
vector<int> j_list = {0, 0, -1, 1};

vector<vector<int>> grid;
int n, m;
int ice_cnt = 0;

int BFS(int si, int sj){
    int ret = 0;
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    vis[si][sj] = true;
    q.push({si,sj});
    while(!q.empty()){
    	int i = q.front().first;
		int j = q.front().second;
		q.pop();
        ret++;
        for(int d=0; d<4; ++d){
            int ni=i+i_list[d], nj=j+j_list[d];
            if(ni<0||ni>=n||nj<0||nj>=m) continue;
            if(vis[ni][nj]) continue;
            if(grid[ni][nj]==0) continue;
            vis[ni][nj]=true;
            q.push({ni,nj});
        }
    }
    return ret;
}

int Check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0){
                int num = BFS(i,j);
                if(num == ice_cnt) return 1;   
                else return 0;                
            }
        }
    }
    return -1; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j]!=0) ice_cnt++;
        }
    }

    int years = 0;
    while(true){
        int chk = Check();
        if(chk == 0){          
            cout << years << '\n';
            break;
        }else if(chk == -1){    
            cout << 0 << '\n';
            break;
        }

        vector<vector<int>> melt(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                int water=0;
                for(int d=0; d<4; ++d){
                    int ni=i+i_list[d], nj=j+j_list[d];
                    if(ni<0||ni>=n||nj<0||nj>=m) continue;
                    if(grid[ni][nj]==0) water++;
                }
                melt[i][j] = water;
            }
        }

        ice_cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                grid[i][j] = max(0, grid[i][j] - melt[i][j]);
                if(grid[i][j]>0) ice_cnt++;
            }
        }

        years++;
    }
}