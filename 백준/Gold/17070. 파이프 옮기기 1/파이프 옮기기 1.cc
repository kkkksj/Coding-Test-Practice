#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> house;
int ans = 0;

// dir : 1-가로, 2-세로, 3-대각선
void DFS (int i, int j, int dir){
    if(i<0 || i>=n || j<0 || j>=n || house[i][j] == 1)
        return;
    if(dir == 3 && (house[i-1][j] == 1 || house[i][j-1] == 1))
            return;
    if(i==n-1 && j==n-1){
        ans++;
        return;
    }
    
    if(dir==1){
        DFS(i, j+1, 1);
        DFS(i+1, j+1, 3);
    }
    else if(dir==2){
        DFS(i+1, j, 2);
        DFS(i+1, j+1, 3);
    }
    else{
        DFS(i, j+1, 1);
        DFS(i+1, j, 2);
        DFS(i+1, j+1, 3);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    house.resize(n, vector<int> (n));

    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++)
            cin >> house[i][j];

    DFS(0, 1, 1);

    cout << ans << '\n';
}