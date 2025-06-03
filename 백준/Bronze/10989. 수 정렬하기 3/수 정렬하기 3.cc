#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std; 

vector<int> arr(10001, 0);
int n, num;

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> num;
        arr[num] += 1;
    }

    for(int i=1; i<10001; i++){
        while(arr[i]){
            cout << i << '\n';
            arr[i] -= 1;
        }
    }
}