#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    string n;
    cin >> n;
    
    long long ans = 0;
    for(size_t i=1; i<n.size(); i++)
        ans += i * (9*pow(10,i-1));
    
    ans += (stoi(n) - pow(10, n.size()-1) + 1) * n.size();

    cout << ans;
}