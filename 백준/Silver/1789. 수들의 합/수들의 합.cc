#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long s;
    cin >> s;
    
    long long cnt=0;
    for(long long n=1; n<=s; n++){
        if(n>s)
            break;
        cnt++;
        s -= n;
    }
    cout << cnt << '\n';
}