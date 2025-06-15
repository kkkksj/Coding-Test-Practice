#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() { 
    long long n;
    cin >> n;
    
    long long gap = 3;
    long long num = 0;
    long long cnt = 1;
    while(1){
        num += gap;
        gap += 2;
        if(num >= n)
            break;
        cnt++;
    }
    cout << cnt << '\n';
}