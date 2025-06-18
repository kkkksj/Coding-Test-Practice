#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int Start_B(vector<string> &chess, int x, int y){
    int diff = 0;
    for(int i=0; i<8; i++){
        if(i % 2 == 0){
            for(int j = 0; j<8; j++){
                if(j % 2 == 0)
                    diff += (chess[x+i][y+j]=='W');
                else
                    diff += (chess[x+i][y+j]=='B');
            }
        }
        else{
            for(int j = 0; j<8; j++){
                if(j % 2 == 0)
                    diff += (chess[x+i][y+j]=='B');
                else
                    diff += (chess[x+i][y+j]=='W');
            }
        }
    }
    return diff;
}

int Start_W(vector<string> &chess, int x, int y){
    int diff = 0;
    for(int i=0; i<8; i++){
        if(i % 2 == 0){
            for(int j = 0; j<8; j++){
                if(j % 2 == 0)
                    diff += (chess[x+i][y+j]=='B');
                else
                    diff += (chess[x+i][y+j]=='W');
            }
        }
        else{
            for(int j = 0; j<8; j++){
                if(j % 2 == 0)
                    diff += (chess[x+i][y+j]=='W');
                else
                    diff += (chess[x+i][y+j]=='B');
            }
        }
    }
    return diff;
}

int main() { 
    int n, m;
    cin >> n >> m; 

    cin.ignore();
    vector<string> chess (n);
    for(int i=0; i<n; i++)
        getline(cin, chess[i]);

    int ans = 65;
    for(int i=0; i<n-7; i++){
        for(int j=0; j<m-7; j++)
            ans = min(ans, min(Start_B(chess, i, j), Start_W(chess, i, j)));
    }
    cout << ans << '\n';
}