#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Sort_XY(vector<int>a, vector<int> b){
    if(a[1] != b[1])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> xy(n, vector<int> (2));
    for(int i=0; i<n; i++)
        cin >> xy[i][0] >> xy[i][1];
    sort(xy.begin(), xy.end(), Sort_XY);

    for(int i=0; i<n; i++)
        cout << xy[i][0] << ' ' <<  xy[i][1] << '\n'; 
}