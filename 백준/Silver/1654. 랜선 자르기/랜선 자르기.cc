#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find(vector<long long> &lens, int n){
    long long l = 1;
    long long h = lens[0];
    long long mid;
    long long ans;
    while(l <= h){
        mid = (l+h)/2;
        ans = 0;
        for(long long l : lens){
            if(l < mid || ans >= n)
                break;
            ans += (l/mid);
        }
        if(ans < n)
            h = mid-1;
        else
            l = mid+1;
    }

    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<long long> lens (k);
    for(int i=0; i<k; i++)
        cin >> lens[i];
    
    sort(lens.begin(), lens.end(), greater<int> ());

    cout << find(lens, n) << '\n';
}