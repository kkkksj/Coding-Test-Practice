#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool IsPrime(int num){
    if(num == 1)
        return false;
    for(int n=2; n<=sqrt(num); n++){
        if(num % n == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int num;
    while(true){
        cin >> num;
        if(num == 0)
            break;
            
        int ans = 0;
        for(int n = num+1; n<=num*2; n++)
            if(IsPrime(n))
                ans++;
        cout << ans << '\n';
    }
}