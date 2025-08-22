#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> grid(n, vector<int> (m, 1));
    for(vector<int> pos : puddles){
        grid[pos[1]-1][pos[0]-1] = 0;
        if(pos[0]-1 == 0)
            for(int j=pos[1]; j<n; j++)
                grid[j][0] = 0;
        else if(pos[1]-1 == 0)
            for(int i=pos[0]; i<m; i++)
                grid[0][i] = 0;
    }
    
    
    for(int i=1; i<n; i++)
        for(int j=1; j<m; j++){
            if(grid[i][j] == 0)
                continue;
            grid[i][j] = (grid[i-1][j]+grid[i][j-1])%1000000007;
        }
    answer = grid[n-1][m-1] % 1000000007;
    return answer;
}