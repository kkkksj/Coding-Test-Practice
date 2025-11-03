#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int L, R, C;
vector<vector<string>> bulding;

vector<int> l_list = {-1, 1, 0, 0, 0, 0};
vector<int> r_list = {0, 0, 0, 0, -1, 1};
vector<int> c_list = {0, 0, -1, 1, 0, 0};

struct POS {
    int l, r, c;
    int cnt;
};


int BFS(int sl, int sr, int sc, int el, int er, int ec){
    queue<POS> q;
    q.push({sl, sr, sc, 0});
    vector<vector<vector<bool>>> visited(L, vector<vector<bool>> (R, vector<bool>(C, false)));
    visited[sl][sr][sc] = true;

    while(!q.empty()){
        int now_l = q.front().l;
        int now_r = q.front().r;
        int now_c = q.front().c;
        int cnt = q.front().cnt;
        q.pop(); 

        if(now_l==el && now_r==er && now_c==ec)
            return cnt;

        for(int d=0; d<6; d++){
            int next_l = now_l + l_list[d];
            int next_r = now_r + r_list[d];
            int next_c = now_c + c_list[d];

            if(next_l<0 || next_l>=L || next_r<0 || next_r>=R || next_c<0 || next_c>=C || visited[next_l][next_r][next_c])
                continue;
            if(bulding[next_l][next_r][next_c] == '#')
                continue;

            visited[next_l][next_r][next_c] = true;
            q.push({next_l, next_r, next_c, cnt+1});
        }
    }

    return -1;
}   

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    while(true){
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0)
            break;
        bulding.assign(L, vector<string>(R+1, ""));

        string tmp = "";
        int sl, sr, sc, el, er, ec;
        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                cin >> bulding[i][j];
                if(bulding[i][j] == "")
                    continue;
                for(int k=0; k<C; k++)
                    if(bulding[i][j][k]=='S'){
                        sl = i; sr = j; sc = k; 
                    }
                    else if(bulding[i][j][k]=='E'){
                        el = i; er = j; ec = k; 
                    }
            }
        }

        int time = BFS(sl, sr, sc, el ,er, ec);
        if(time == -1)
            cout << "Trapped!" << '\n';
        else
            cout << "Escaped in " << time << " minute(s)." << '\n';
    }
}