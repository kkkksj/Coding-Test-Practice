#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int main() { 
    int coin;
    cin >> coin;

    vector<int> rest (100001, 0);
    rest[1] = -1;
    rest[2] = 1;
    rest[3] = -1;
    rest[4] = 2;
    rest[5] = 1;  
    rest[6] = 3; 

    for(int i=7; i<coin+1; i++){
        if(rest[i-5] == -1){
            if(rest[i-2] == -1)
                rest[i] = -1;
            else
                rest[i] = rest[i-2] + 1;
        }
        else if(rest[i-2] == -1){
            if(rest[i-5] == -1)
                rest[i] = -1;
            else
                rest[i] = rest[i-5] + 1;
        }
        else{
            if(rest[i-2] <= rest[i-5])
                rest[i] = rest[i-2] + 1;
            else
                rest[i] = rest[i-5] + 1;
        }
    }
    cout << rest[coin] << '\n';
}