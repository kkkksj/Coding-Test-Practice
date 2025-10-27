#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> grid;
int n, m;
int vi, vj, vd;
int ans = 0;

vector<int> i_list = {-1, 0, 1, 0};
vector<int> j_list = {0, 1, 0, -1};
vector<int> opposite = {2, 3, 0, 1};

bool IsClean(){
	for(int d=0; d<4; d++){
		int next_i = vi + i_list[d];
		int next_j = vj + j_list[d];

		if(next_i<0 || next_i>=n || next_j<0 || next_j>=m)
			continue;
		if(grid[next_i][next_j] == 0)
			return false;
	}
	return true;
}

void Move(){
	while(true){
		// 1. 현재 칸이 청소됐는지 체크
		if(grid[vi][vj] == 0){
			grid[vi][vj] = 2;	// 청소한 곳은 2
			ans++;
		}
		if(IsClean()){
			int back_d = opposite[vd];
			int back_i = vi + i_list[back_d];
			int back_j = vj + j_list[back_d];

			if(back_i>=0 && back_i<n && back_j>=0 && back_j<m){
				if(grid[back_i][back_j]==1)
					return;
				vi = back_i;
				vj = back_j;
			}
		}
		else{
			vd = (vd+3)%4;
			int next_i = vi + i_list[vd];
			int next_j = vj + j_list[vd];
			if(next_i>=0 && next_i<n && next_j>=0 && next_j<m)
				if(grid[next_i][next_j]==0){
					vi = next_i;
					vj = next_j;
				}
		}
	}
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

	cin >> n >> m;
	grid.assign(n, vector<int> (m+1));

	cin >> vi >> vj >> vd;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> grid[i][j];

	Move();

	cout << ans << '\n';
}