#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool IsPrime(int num){
    for(int n=2; n<=sqrt(num); n++)
        if(num%n == 0)
            return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;

    int num;
    for(int i=0; i<t; i++){
        cin >> num;
        for(int n=num/2; n>1; n--)
            if(IsPrime(n))
                if(IsPrime(num-n)){
                    cout << n << ' ' << num-n << '\n';
                    break;
                }
    }
}