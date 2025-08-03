#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long a, b, c;

long long recursive(long long b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a%c;
    long long tmp = recursive(b/2) % c;
    if(b%2 == 0)
        return tmp * tmp % c;
    else
        return (tmp * tmp % c) * (a % c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;

    cout << recursive(b) % c;
}