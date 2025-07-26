#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n, m;

int howmany5(long long num){
    int ret = 0;
    for(long long i=5; i<=num; i*=5)
        ret += num/i;
    return ret;
}

int howmany2(long long num){
    int ret = 0;
    for(long long i=2; i<=num; i*=2)
        ret += num/i;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    int five, two;
    five = howmany5(n) - howmany5(m) - howmany5(n-m);
    two = howmany2(n) - howmany2(m) - howmany2(n-m);

    cout << min(five, two) << '\n';
}