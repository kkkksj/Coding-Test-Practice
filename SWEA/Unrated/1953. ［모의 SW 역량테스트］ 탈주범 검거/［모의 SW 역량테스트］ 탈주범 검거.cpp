#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, r, c, l;
vector<vector<int>> tunnel;

vector<int> i_list = {-1, 1, 0, 0};
vector<int> j_list = {0, 0, -1, 1};

bool IsPossibleUp(int now_pipe, int next_pipe){
    if(now_pipe==3 || now_pipe==5 || now_pipe==6)
        return false;
    if(next_pipe==1 || next_pipe==2 || next_pipe==5 || next_pipe==6)
        return true;
    return false;
}
bool IsPossibleDown(int now_pipe, int next_pipe){
    if(now_pipe==3 || now_pipe==4 || now_pipe==7)
        return false;
    if(next_pipe==1 || next_pipe==2 || next_pipe==4 || next_pipe==7)
        return true;
    return false;
}
bool IsPossibleLeft(int now_pipe, int next_pipe){
    if(now_pipe==2 || now_pipe==4 || now_pipe==5)
        return false;
    if(next_pipe==1 || next_pipe==3 || next_pipe==4 || next_pipe==5)
        return true;
    return false;
}
bool IsPossibleRight(int now_pipe, int next_pipe){
    if(now_pipe==2 || now_pipe==6 || now_pipe==7)
        return false;
    if(next_pipe==1 || next_pipe==3 || next_pipe==6 || next_pipe==7)
        return true;
    return false;
}

struct Info{
    int i, j, t;
};


int BFS(){
    int ret = 0;
    queue<Info> q;
    vector<vector<bool>> visited (n, vector<bool>(m, false));
    
    q.push({r, c, 1});
    visited[r][c] = true;

    while(!q.empty()){
        auto [now_i, now_j, now_t] = q.front();
        q.pop();
        int now_pipe = tunnel[now_i][now_j];
        ret++;

        if(now_t == l)
            continue;

        for(int d=0; d<4; d++){
            int next_i = now_i + i_list[d];
            int next_j = now_j + j_list[d];

            if(next_i<0 || next_i>=n || next_j<0 || next_j>=m || visited[next_i][next_j])
                continue;

            int next_pipe = tunnel[next_i][next_j];
            if(next_pipe==0)
                continue;

            if(d==0){
                if(!IsPossibleUp(now_pipe, next_pipe))
                    continue;
            }
            else if(d==1){
                if(!IsPossibleDown(now_pipe, next_pipe))
                    continue;
            }
            else if(d==2){
                if(!IsPossibleLeft(now_pipe, next_pipe))
                    continue;
            }
            else{
                if(!IsPossibleRight(now_pipe, next_pipe))
                    continue;
            }

            q.push({next_i, next_j, now_t+1});
            visited[next_i][next_j] = true;
        }
    }
    return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n >> m >> r >> c >> l;
        tunnel.assign(n, vector<int> (m, 0));

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> tunnel[i][j];
        cout << '#' << test_case << ' ' << BFS() << '\n';        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}