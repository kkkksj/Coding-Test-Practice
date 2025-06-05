#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
    int n;
    cin >> n;

    vector<int> neg_arr(1000001, 0);
    vector<int> pos_arr(1000001, 0);
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        
        if(num < 0)
            neg_arr[-num]++;
        else
            pos_arr[num]++;
    }

    for(int i=1000000; i>0; i--)
        if(neg_arr[i])
            cout << -i << '\n';
    for(int i=0; i<1000001; i++)
        if(pos_arr[i])
            cout << i << '\n';  
}