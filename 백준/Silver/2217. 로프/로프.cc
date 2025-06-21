#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weight (n);
    for(int i=0; i<n; i++)
        cin >> weight[i];
    sort(weight.begin(), weight.end());

    int max_weight = 0;
    for(int i=n; i>0; i--){
        max_weight = max(weight[n-i] * i, max_weight);
    }

    cout << max_weight << '\n';
}