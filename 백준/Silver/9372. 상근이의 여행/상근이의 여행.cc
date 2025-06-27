#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    int n, m;
    int a, b;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        cout << n-1 << '\n';
        for(int i=0; i<m; i++)
            cin >> a >> b;
    }
}