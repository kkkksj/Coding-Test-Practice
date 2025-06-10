#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int cm;
    cin >> cm;

    int sum = 0;    
    int now_cm = 64;
    int cnt = 0;

    while(sum < cm){
        if(sum+now_cm <= cm){
            sum += now_cm;
            cnt++;
        }  
        now_cm /= 2;      
    }
    cout << cnt << '\n';
}