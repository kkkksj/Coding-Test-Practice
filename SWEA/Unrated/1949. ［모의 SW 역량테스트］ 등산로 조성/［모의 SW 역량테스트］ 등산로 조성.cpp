#include<iostream>
#include<vector>

using namespace std;
int n, k;
vector<vector<int>> map_h;
vector<vector<bool>> visited;
int ans = 0;
vector<int> i_list = {-1, 1, 0, 0};
vector<int> j_list = {0, 0, -1, 1};

void DFS(int i, int j, int h, int cnt, bool used){
    visited[i][j] = true;
    ans = max(ans, cnt);

    for(int d=0; d<4; d++){
        int next_i = i + i_list[d];
        int next_j = j + j_list[d];

        if(next_i<0 || next_i>=n || next_j<0 || next_j>=n || visited[next_i][next_j])
            continue;
        
        int next_h = map_h[next_i][next_j];
        if(next_h < h)   
            DFS(next_i, next_j, next_h, cnt+1, used);
        else if(next_h-h < k && !used)
            DFS(next_i, next_j, h-1, cnt+1, true);
    }

    visited[i][j] = false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
        cin >> n >> k;

        map_h.assign(n, vector<int> (n, 0));
        int max_h = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                int num;
                cin >> num;
                map_h[i][j] = num;
                max_h = max(max_h, num);
            }  
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                if(map_h[i][j] == max_h){
                    visited.assign(n, vector<bool> (n, false));
                    DFS(i, j, max_h, 1, false);
                }
            }
        cout << '#' << test_case << ' ' << ans << '\n';
        
        ans = 0;        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}