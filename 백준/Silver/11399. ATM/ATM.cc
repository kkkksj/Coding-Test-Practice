#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() { 
    int n;
    cin >> n;

    vector<int> time (n);
    for(int i=0; i<n; i++)
        cin >> time[i];
    sort(time.begin(), time.end());

    int sum=time[0];
    for(int i=1; i<n; i++){
        time[i] = time[i-1]+time[i];
        sum += time[i];
    }
    cout << sum << '\n';
}