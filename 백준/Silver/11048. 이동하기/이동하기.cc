#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int> (m, 0));
    int candy;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> candy;
            maze[i][j] = candy;
            if(j > 0)
                maze[i][j] = max(maze[i][j], maze[i][j-1] + candy);
            if(i > 0)
                maze[i][j] = max(maze[i][j], maze[i-1][j] + candy);
            if(i > 0 && j > 0)
                maze[i][j] = max(maze[i][j], maze[i-1][j-1] + candy);
        }

    cout << maze[n-1][m-1];
}