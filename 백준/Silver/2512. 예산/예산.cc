#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int n, int goal){
    int l = 1;
    int h = arr[n-1];
    int m;
    while(l <= h){
        m = (l+h)/2;
        long long sum = 0;
        for(int tmp : arr){
            if(tmp <= m)
                sum += tmp;
            else
                sum += m;
        }
        if(sum > goal)
            h = m - 1;
        else
            l = m + 1;
    }
    return h;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int m;
    cin >> m;
    
    cout << BinarySearch(arr, n, m) << '\n';
}