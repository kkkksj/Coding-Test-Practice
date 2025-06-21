#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;

    vector<long long> A (n+1, 0);
    int num;
    for(int i=1; i<n+1; i++){
        cin >> num;
        A[i] = A[i-1] + num;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n+1; j++){
            if(A[j] - A[i] == m){
                ans++;
                break;
            }
            if(A[j] - A[i] > m)
                break;
        }
    }
    cout << ans << '\n';
}