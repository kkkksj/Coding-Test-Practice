#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() { 
    int n;
    cin >> n;

    vector<int> neg_arr (1001, 0);
    vector<int> pos_arr (1001, 0);
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        if(num < 0)
            neg_arr[-num] = 1;
        else   
            pos_arr[num] = 1;
    }
    
    for(int i=1000; i>0; i--){
        if(neg_arr[i])
            cout << -i << ' ';
    }
    for(int i=0; i<1001; i++){
        if(pos_arr[i])
            cout << i << ' ';
    }
}