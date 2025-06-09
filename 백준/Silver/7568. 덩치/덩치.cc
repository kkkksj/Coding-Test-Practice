#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> dungchi(n, vector<int> (2));
    for(int i=0; i<n; i++){
        cin >> dungchi[i][0] >> dungchi[i][1];
    }

    vector<int> rank(n, 1);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if((dungchi[i][0] < dungchi[j][0]) and (dungchi[i][1] < dungchi[j][1]))
                rank[i] += 1;
    
    for(int k : rank)
        cout << k << ' ';
}