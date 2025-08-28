#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = n-1;
    int ans_i = 0;
    int ans_j = n-1;
    int ans = INT_MAX;
    while(i < j){
        int plus = arr[i] + arr[j];
        if(abs(plus) < ans){
            ans_i = i;
            ans_j = j;
            ans = abs(plus);
        } 
        if(plus < 0)
            i++;
        else if(plus > 0)
            j--;
        else{
            i++;
            j--;
        }
    }

    cout << arr[ans_i] << ' ' << arr[ans_j] << '\n';
}