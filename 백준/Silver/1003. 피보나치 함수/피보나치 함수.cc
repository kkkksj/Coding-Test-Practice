#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int n;
    for(int j=0; j<t; j++){
        cin >> n;

        vector<vector<int>> pibo(n+1, vector<int>(2));
        pibo[0] = {1, 0};
        if(n>0)
            pibo[1] = {0, 1};
        for(int i=2; i<n+1; i++){
            pibo[i][0] = pibo[i-1][0]+pibo[i-2][0];
            pibo[i][1] = pibo[i-1][1]+pibo[i-2][1];
        }   
        
        cout << pibo[n][0] << ' ' << pibo[n][1] << '\n';
    }
}