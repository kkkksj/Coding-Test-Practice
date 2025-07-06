#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GCD(int a, int b){
    if(b==0)
        return a;
    return GCD(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int up, down;
    up = a1*b2 + a2*b1;
    down = b1*b2;

    int gcd;
    gcd = GCD(up, down);
    
    cout << up/gcd << ' ' << down/gcd;
}