#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt=0;
    for(int i=2; i<=int(sqrt(n)); i++){
        cnt++;
        if(n%i==0){
            cnt = n - n/i;
            break;
        }
        if(i==int(sqrt(n)))
            cnt = n-1;
    }
    cout << cnt << endl;
}