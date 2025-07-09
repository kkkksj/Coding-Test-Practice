#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void draw(int n){
    if(n==0){
        cout << '-';
        return;
    }

    draw(n-1);
    for(int i=0; i<pow(3,n-1); i++)
        cout << ' ';
    draw(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    while(cin>>n){
        draw(n);
        cout << '\n';
    }
}