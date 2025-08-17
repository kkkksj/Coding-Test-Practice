#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

#define MOD 4
int n;
vector<vector<int>> board;
vector<vector<int>> tmp;
vector<vector<int>> decision_dir(6);
unordered_map<int, vector<pair<int, int>>> wormhall_list;

vector<int> i_list = {-1, 0, 1, 0}; // 상 우 좌 하
vector<int> j_list = {0, 1, 0, -1}; // 상 우 좌 하

int PLAY(int i, int j, int dir){
    int next_i = i;
    int next_j = j;
    int score = 0;
    while(true){
        while(true){
            next_i += i_list[dir];
            next_j += j_list[dir];

            if((next_i==i && next_j==j) || (next_i<0 || next_i>=n) || (next_j<0 || next_j>=n) || board[next_i][next_j]!=0) 
                break;
        }
        if(next_i==i && next_j==j){
            break;  // 현재 위치로 돌아오면 종료
        }

        if((next_i<0 || next_i>=n) || (next_j<0 || next_j>=n)){
            dir = (dir+2)%MOD;  // 격자를 벗어나면 == 벽을 만나면, 방향을 반대로 돌림
            score++;

        }
        else if(board[next_i][next_j]>=1 && board[next_i][next_j]<=5){  // 블록을 만나면
            int block = board[next_i][next_j];
            dir = (dir + decision_dir[block][dir] + MOD) % MOD; // 만난 블록과 현재 방향을 고려해 방향을 돌림
            score++;
        }
        else if(board[next_i][next_j]>=6 && board[next_i][next_j]<=10){ // 웜홀을 만나면
            int wormhall = board[next_i][next_j];
            if(wormhall_list[wormhall][0] == make_pair(next_i, next_j)){
                next_i = wormhall_list[wormhall][1].first;
                next_j = wormhall_list[wormhall][1].second;
            }
            else{
                next_i = wormhall_list[wormhall][0].first;
                next_j = wormhall_list[wormhall][0].second;
            }
        }
        else if(board[next_i][next_j]==-1)  // 블랙홀을 만나면 종료
            break;
    }

    return score;
}

int main(int argc, char** argv)
{
    for(int i=1; i<6; i++){
        if(i==1)    decision_dir[i] = {2, 2, -1, 1};
        else if(i==2)    decision_dir[i] = {1, 2, 2, -1};
        else if(i==3)    decision_dir[i] = {-1, 1, 2, 2};
        else if(i==4)    decision_dir[i] = {2, -1, 1, 2};
        else     decision_dir[i] = {2, 2, 2, 2};
    }

	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        
        board.resize(n, vector<int> (n));

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                int num;
                cin >> num;
                board[i][j] = num;
                
                if(num>=6 && num<=10)
                    wormhall_list[num].push_back({i, j});
            }
        
        int max_score = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(board[i][j] == 0)
                    for(int dir=0; dir<4; dir++)
                        max_score = max(PLAY(i, j, dir), max_score);
                    
        
        cout << '#' << test_case << ' ' << max_score << '\n';
                    
        board.clear();      // board 초기화
        tmp.swap(board);    // board 초기화
        wormhall_list.clear();
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}