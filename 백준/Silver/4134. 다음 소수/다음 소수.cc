#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

bool IsPrime(long long num){
    if(num == 1)
        return 0;
    for(long long i=2; i<=sqrt(num); i++)
        if(num%i == 0)
            return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long n;
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n;
        if(n==0)
            cout << 2 << '\n';
        else{
            for(long long num = n; num<num*2; num++){
                if(IsPrime(num)){
                    cout << num << '\n';
                    break;
                }
            }
        }
    }
}