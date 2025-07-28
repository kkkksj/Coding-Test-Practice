#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector<int> x_list = {-1, 0, 1, 0};
vector<int> y_list = {0, -1, 0, 1};

int n, m;
int ans = 0;

void DFS(vector<string> &campus, int x, int y){
    if(campus[y][x] == 'P')
        ans++;
    campus[y][x] = 'X';
    
    for(int i=0; i<4; i++){
        int next_x = x + x_list[i];
        int next_y = y + y_list[i];

        if((next_x >=0 && next_x < m) && (next_y >=0 && next_y < n))
            if(campus[next_y][next_x] != 'X')
                DFS(campus, next_x, next_y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<string> campus(n);
    int start_x, start_y;
    for(int i=0; i<n; i++){
        cin >> campus[i];
        int idx = campus[i].find("I"); 
        if(idx != (int)string::npos){
            start_x = idx;
            start_y = i;
        }            
    }
    
    DFS(campus, start_x, start_y);
    if(ans == 0)
        cout << "TT" << '\n';
    else
        cout << ans << '\n';
}