#include<iostream>
#include<vector>

using namespace std;

vector<int> i_list = {-1, 1, 0, 0};
vector<int> j_list = {0, 0, -1, 1};
vector<int> opposite = {1, 0, 3, 2};
vector<vector<int>> grid (2001, vector<int> (2001, -1));    // 위치한 원자 번호 기록
vector<vector<int>> visited (2001, vector<int> (2001, 0));  // 충돌하는 원자 개수 기록

struct INFO {
    int i, j, dir, energy;
    bool alive;
};

int Simulation(int n, vector<INFO> &atoms){
    int dead_n = 0;
    int ret = 0;
    
    int next_i, next_j;
    while(dead_n != n){
        for(int t=0; t<n; t++){ // 범위 벗어 나는 애들 체크
            INFO &atom = atoms[t];
            if(atom.alive == false)
                continue;
            next_i = atom.i + i_list[atom.dir];
            next_j = atom.j + j_list[atom.dir];
            if(next_i<0 || next_i>2000 || next_j<0 || next_j>2000){
                atom.alive = false;
                dead_n++;
            }
            else
                grid[atom.i][atom.j] = t;   // 원자 번호 기록
        }

        for(INFO &atom : atoms){ // 흔적 안 남기고 중간에서 충돌하는 애들 체크
            if(atom.alive == false)
                continue;
            next_i = atom.i + i_list[atom.dir];
            next_j = atom.j + j_list[atom.dir];
            int next_num = grid[next_i][next_j];
            
            if(next_num!=-1 && opposite[atom.dir]==atoms[next_num].dir){
                atoms[next_num].alive = false;
                atom.alive = false;
                grid[atom.i][atom.j] = -1;
                grid[next_i][next_j] = -1;
                ret += (atoms[next_num].energy + atom.energy);
                dead_n += 2;
            }

            else    // 위의 조건에 해당하지 않는다면 다음 이동 좌표에 체크해두기
                visited[next_i][next_j] += 1;
        }

        for(INFO &atom : atoms){ // 원자 이동시키기
            if(atom.alive == false)
                continue;
            next_i = atom.i + i_list[atom.dir];
            next_j = atom.j + j_list[atom.dir];

            if(visited[next_i][next_j] == 1){   // 이동할 곳에 원자가 하나라면 == 충돌하지 않음을 의미
                grid[atom.i][atom.j] = -1;      // 초기화 해주기
                atom.i = next_i;
                atom.j = next_j;
                visited[next_i][next_j] = 0;    // 초기화 해주기
            }

            else{   // 이동할 곳에 원자가 다수면 == 충돌했음을 의미
                for(int d=0; d<4; d++){
                    int before_i = next_i + i_list[d];
                    int before_j = next_j + j_list[d];
                    int before_num = grid[before_i][before_j];
                    if(before_num == -1)
                        continue;
                    if(atoms[before_num].dir == opposite[d]){
                        grid[before_i][before_j] = -1;      // 초기화 해주기
                        ret += atoms[before_num].energy;    // 에너지 얻고
                        atoms[before_num].alive = false;     // 소멸
                    }
                }
                dead_n += visited[next_i][next_j];
                visited[next_i][next_j] = 0;                // 초기화 해주기
            }   
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
        int n;
        cin >> n;

        vector<INFO> atoms(n);
        for(int i=0; i<n; i++){
            int x, y, d, e;
            cin >> x >> y >> d >> e;
            atoms[i] = {1000-y, 1000+x, d, e, true};
        }

        cout << '#' << test_case << ' ' << Simulation(n, atoms) << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}