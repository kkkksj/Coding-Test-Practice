#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<int> i_list = {0, 1, 0, -1};
vector<int> j_list = {1, 0, -1, 0};

void Rot(int si, int sj, int h, int w){
    int tmp = grid[si][sj];
    int now_i = si;
    int now_j = sj;
    int k=0;

    while(k<4){
        int next_i = now_i+i_list[k];
        int next_j = now_j+j_list[k]; 

        if(next_i==si && next_j==sj)
            break;
        if(si<=next_i && next_i<si+h && sj<=next_j && next_j<sj+w){
            grid[now_i][now_j] = grid[next_i][next_j];
            now_i = next_i;
            now_j = next_j;
        }
        else
            k++;
    }
    grid[si+1][si] = tmp;
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int t;
    cin >> n >> m >> t;

    grid.assign(n, vector<int> (m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    
    while(t--){
        int h = n, w = m;
        int si = 0, sj = 0;
        while(h>0 && w>0){
            Rot(si, sj, h, w);
            si++;   sj++;
            h -= 2; w -= 2;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout << grid[i][j] << ' ';
        cout << '\n';
    }
}