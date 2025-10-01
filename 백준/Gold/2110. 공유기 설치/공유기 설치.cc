#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> home;

int BinarySearch(){
    int s=1, e=home[n-1]-home[0];
    int mid;
    while(s<=e){
        mid = (s+e)/2;
        int cnt = 1;
        int now = home[0];

        for(int i=1; i<n; i++)
            if(home[i] >= now + mid){
                cnt++;
                now = home[i];
            }
        if(cnt >= c)
            s = mid + 1;
        else    
            e = mid - 1;
    }
    return e;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    home.assign(n, 0);

    for(int i=0; i<n; i++)
        cin >> home[i];
    sort(home.begin(), home.end());

    cout << BinarySearch() << '\n';
}