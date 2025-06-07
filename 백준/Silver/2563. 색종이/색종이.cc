#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    vector<vector<int>> paper(101, vector<int> (101, 0));

    int n;
    cin >> n;

    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        for(int j=x+1; j<x+11; j++)
            for(int k=y+1; k<y+11; k++)
                paper[j][k] = 1;
    }

    int ans=0;
    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            if(paper[i][j] == 1)
                ans++;
    cout << ans << endl;
}