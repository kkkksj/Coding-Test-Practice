#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<double> set6 (m);
    vector<double> each (m);
    for(int i=0; i<m; i++)
        cin >> set6[i] >> each[i];
    sort(set6.begin(), set6.end());
    sort(each.begin(), each.end());
    
    cout << min(min(n*each[0], floor(n/6)*set6[0] + ((n - floor(n/6)*6)*each[0])), set6[0]*(round(n/6 + 0.5)))<< '\n';
}