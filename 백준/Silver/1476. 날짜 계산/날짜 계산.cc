#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int s, e, m;
    cin >> s >> e >> m;
    
    int cnt_s = 0;
    int cnt_e = 0;
    int cnt_m = 0;
    int year = 0;
    while(1){
        cnt_s = cnt_s%15+1;
        cnt_e = cnt_e%28+1;
        cnt_m = cnt_m%19+1;
        year++;
        if((cnt_s == s) and (cnt_e == e) and (cnt_m == m))
            break;
    }
    cout << year << '\n';
}