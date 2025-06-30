#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool IsPrime(int num){
    if(num == 1)
        return 0;
    for(int i=2; i<=sqrt(num); i++)
        if(num % i == 0)
            return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    for(int num=m; num<=n; num++)
        if(IsPrime(num))
            cout << num << '\n';    
}