#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sort_xy(vector<int> a, vector<int> b){
    if(a[0] != b[0])
        return a[0] < b[0];
    return a[1] < b[1];
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> xy(n);
    int a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        xy[i].push_back(a);
        xy[i].push_back(b);
    }

    sort(xy.begin(), xy.end(), sort_xy);

    for(vector<int> a : xy)
        cout << a[0] << ' ' << a[1] << '\n';
}