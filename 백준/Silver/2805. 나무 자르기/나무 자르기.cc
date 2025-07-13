#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find(vector<int> trees, int m){
    int h=trees[0];
    int l=trees[0] - m;

    long long mid;
    while(h >= l){
        mid = (h+l)/2;
        long long sum = 0;
        for(int t : trees){
            if(mid >= t || sum >= m)
                break;
            sum += t-mid;
        }
        if(sum < m)
            h = mid-1;
        else
            l = mid+1;
    }
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> trees (n);
    for(int i=0; i<n; i++)
        cin >> trees[i];
    
    sort(trees.begin(), trees.end(), greater<int> ());

    cout << find(trees, m) << '\n';
}