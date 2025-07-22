#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<vector<int>>> dp (21, vector<vector<int>> (21, vector<int> (21)));

int R(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0)
        return 1;
    if(a>20 || b>20 || c>20)
        return R(20, 20, 20);
    if(dp[a][b][c])
        return dp[a][b][c]; 
    if(a<b && b<c){
        dp[a][b][c] = R(a, b, c-1) + R(a, b-1, c-1) - R(a, b-1, c);
        return dp[a][b][c];
    }
    dp[a][b][c] = R(a-1, b, c) + R(a-1, b-1, c) + R(a-1, b, c-1) - R(a-1, b-1, c-1);
    return dp[a][b][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c;
    while(true){
        cin >> a >> b >> c;
        if(a==-1 && b==-1 && c==-1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << R(a, b, c) << '\n';
    }
}