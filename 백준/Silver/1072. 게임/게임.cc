#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    double x, y;
    cin >> x >> y;

    int origin_per = floor((y*100)/x);
    if(origin_per >= 99)
        cout << -1 << '\n';
    else{
        int s=0;
        int e=1000000000;
        int mid;
        while(s <= e){
            mid = (e+s)/2;
            if(floor(((y+mid)*100)/(x+mid)) == origin_per)
                s = mid + 1;
            else
                e = mid - 1;
        }
        cout << e+1 << '\n';
    }
}