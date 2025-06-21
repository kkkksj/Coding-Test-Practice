#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int num;
    unordered_set<int> A;
    unordered_set<int> B;
    for(int i=0; i<n; i++){
        cin >> num;
        A.insert(num);
    }
    for(int i=0; i<k; i++){
        cin >> num;
        B.insert(num);
    }
    int ans = 0;
    for(int x : B)
        if(A.find(x) == A.end())
            ans++;
    for(int x : A)
        if(B.find(x) == B.end())
            ans++;    
    cout << ans << '\n';
}