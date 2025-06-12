#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int Sum(vector<vector<int>> arr, int sx, int sy, int ex, int ey){
    int sum=0;
    int y_idx = sy;
    while(sx <= ex and y_idx <= ey){
        sum += arr[sx][y_idx];
        if(sx==ex and y_idx==ey)
            return sum;
        y_idx++;
        if(y_idx > ey){
            y_idx = sy;
            sx++;
        }
    }
    return sum;
}

int main() { 
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr (n+1, vector<int> (m+1));
    for(int i=1; i<n+1; i++)
        for(int j=1; j<m+1; j++)
            cin >> arr[i][j];

    int k;
    cin >> k;

    int s_x, s_y, e_x, e_y;
    for(int i=0; i<k; i++){
        cin >> s_x >> s_y >> e_x >> e_y;
        cout << Sum(arr, s_x, s_y, e_x, e_y) << '\n';
    }
}