#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() { 
    vector<vector<int>> xy (101, vector<int> (101, 0));
    int sx, sy, ex, ey;
    for(int i=0; i<4; i++){
        cin >> sx >> sy >> ex >> ey;
        for(int x=sx; x<ex; x++)
            for(int y=sy; y<ey; y++)
                xy[x][y] = 1;
    }

    int sum = 0;
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            sum += xy[i][j];
            
    cout << sum << '\n';
}