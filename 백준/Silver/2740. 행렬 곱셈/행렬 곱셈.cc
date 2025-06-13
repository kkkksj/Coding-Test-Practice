#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() { 
    int n, m, k;

    // 첫 번째 행렬
    cin >> n >> m;
    vector<vector<int>> metrix1 (n, vector<int> (m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> metrix1[i][j];
    
    // 두 번째 행렬 
    cin >> m >> k;
    vector<vector<int>> metrix2 (m, vector<int> (k));
    for(int i=0; i<m; i++)
        for(int j=0; j<k; j++)
            cin >> metrix2[i][j];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            int sum = 0;
            for(int k=0; k<m; k++)
                sum += (metrix1[i][k] * metrix2[k][j]);
            cout << sum << ' ';
        }
        cout << '\n';
    }
}