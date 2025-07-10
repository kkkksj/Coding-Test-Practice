#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int find(vector<int> B, int num, int m){
    int s = 0;
    int e = m-1;
    int mid;
    while(s <= e){
        mid = (s+e) / 2;
        if(B[mid] >= num)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n, m;
        cin >> n >> m;

        vector<int> A (n);
        vector<int> B (m);
        for(int j=0; j<n; j++)
            cin >> A[j];
        for(int j=0; j<m; j++)
            cin >> B[j];
        sort(B.begin(), B.end());

        int ans = 0;
        for(int num : A){
            if(num < B[0])
                continue;
            if(num > B[m-1])
                ans += m;
            else
                ans += find(B, num, m);
        }
        
        cout << ans << '\n';
    }   
}