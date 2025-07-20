#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int ans = 0;
    while(true){
        if(b == a){
            cout << ans+1 << '\n';
            break;
        }
        if(b < a){
            cout << -1 << '\n';
            break;
        }
        if(b%10 == 1)
            b = (b-1)/10;
        else if(b%2 == 0)
            b /= 2;
        else if(b%2 == 1){
            cout << -1 << '\n';
            break;
        }
        ans++;
    }
}