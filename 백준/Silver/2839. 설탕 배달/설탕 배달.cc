#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() { 
    int n;
    cin >> n;

    vector<int> arr(n+1, -1);
    arr[3] = 1;
    arr[4] = -1;
    arr[5] = 1;
    for(int i=6; i<n+1; i++){
        if(arr[i-3] == -1 and arr[i-5] == -1)
            arr[i] = -1;
        else{
            if(arr[i-3] == -1) 
                arr[i] = arr[i-5] + 1;
            else if(arr[i-5] == -1)
                arr[i] = arr[i-3] + 1;
            else if(arr[i-3] < arr[i-5])
                arr[i] = arr[i-3] + 1;
            else
                arr[i] = arr[i-5] + 1;
        }
    }
    cout << arr[n] << '\n';
}