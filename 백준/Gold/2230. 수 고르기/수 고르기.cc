#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr;
int n;
long long m;
long long ans = 2000000000;

void Find(){
    int s = 0, e = 1;
    while(e<n){
        if(arr[e]-arr[s]>=m){
            ans = min(ans, arr[e]-arr[s]);
            s++;
        }
        else
            e++;
        if(s>e)
            e=s;
    }
    return;
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cin >> n >> m;

    arr.assign(n, 0);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    Find();

    cout << ans << '\n';
}