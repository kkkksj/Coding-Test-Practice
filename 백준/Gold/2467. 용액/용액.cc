#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

inline int absolution(int num){
    if(num < 0)
        return -num;
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int i = 0, j = n-1;
    int ans_i = 0, ans_j = n-1, ans_abs = INT_MAX;
    while(i<j){
        int sumij = arr[i]+arr[j];
        if(absolution(sumij) <= ans_abs){
            ans_i = i;
            ans_j = j;
            ans_abs = absolution(sumij);
        } 
        if(sumij < 0)
            i++;
        else if(sumij>0)
            j--;
        else{
            i++;
            j--;
        }
    }
    cout << arr[ans_i] << ' ' << arr[ans_j] << '\n';
}