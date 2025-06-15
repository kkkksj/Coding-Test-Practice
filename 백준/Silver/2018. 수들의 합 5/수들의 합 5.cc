#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() { 
    int num;
    cin >> num;
    
    int cnt=1;
    int sum;
    for(int i=0; i<num; i++){
        sum = 0;
        for(int j=i+1; j<num; j++){
            sum += j;
            if(sum > num)
                break;
            else if(sum == num){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
}