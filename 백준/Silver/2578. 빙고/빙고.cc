#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool Bingo(vector<vector<int>> &board, vector<int> &x, vector<int> &y, int&d1, int&d2, int num, int &bingo){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(board[i][j] == num){
                x[i]++;
                if(x[i] == 5)
                    bingo++;
                y[j]++;
                if(y[j] == 5)
                    bingo++;
                if(i == j) {
                    d1++;
                    if(d1 == 5)
                        bingo++;
                }
                if(i + j == 4) {
                    d2++;
                    if(d2 == 5)
                        bingo++;
                }
                if(bingo >=3)
                    return 1;
                return 0;
            }
    return 0;
}

int main() {
    vector<vector<int>> board(5, vector<int> (5));
    vector<int> x (5, 0);
    vector<int> y (5, 0);
    int d1 = 0; int d2 = 0;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> board[i][j];
    
    int num;
    int ans = 0; int bingo = 0;
    for(int i=0; i<25; i++){
        ans++;
        cin >> num;
        if(Bingo(board, x, y, d1, d2, num, bingo)){
            break;
        }
    }
    cout << ans << '\n';
}