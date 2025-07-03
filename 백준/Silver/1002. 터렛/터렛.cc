#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int FindCase(int x1, int y1, int x2, int y2, int r1, int r2){
    float dist = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
    if(abs(r1-r2) < dist && dist < r1+r2)
        return 2;
    if((dist != 0 && r1+r2 == dist) || (dist != 0 && abs(r1-r2) == dist))
        return 1;
    if((dist == 0 && abs(r1-r2) != 0) || r1+r2 < dist || dist < abs(r1-r2))
        return 0;
    if(dist == 0 && abs(r1-r2) == 0)
        return -1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int x1, y1, r1, x2, y2, r2;
    for(int i=0; i<t; i++){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        cout << FindCase(x1, y1, x2, y2, r1, r2) << '\n';
    }
}