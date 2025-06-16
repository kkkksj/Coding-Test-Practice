#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() { 
    int n;
    cin >> n;

    vector<int> A (46,0);
    vector<int> B (46,0);
    A[0] = 1; A[1] = 0; A[2] = 1;
    B[0] = 0; B[1] = 1; B[2] = 1; 
    for(int i=3; i<n+1; i++){
        A[i] = A[i-1] + A[i-2];
        B[i] = B[i-1] + B[i-2];
    }

    cout << A[n] << ' ' << B[n] << '\n';
}