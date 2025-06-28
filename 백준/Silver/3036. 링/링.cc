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
    int n;
    cin >> n;

    int first;
    cin >> first;
    int R, gcd;
    for(int i=0; i<n-1; i++){
        cin >> R;
        gcd = GCD(first, R);
        cout << first/gcd << '/' << R/gcd << '\n';
    }
}