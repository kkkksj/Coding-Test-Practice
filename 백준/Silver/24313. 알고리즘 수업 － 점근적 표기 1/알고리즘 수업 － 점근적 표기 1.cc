#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() { 
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    if(a1<=c and a1*n0+a0 <= c*n0)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}