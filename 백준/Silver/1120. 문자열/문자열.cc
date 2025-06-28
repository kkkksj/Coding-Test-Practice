#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

size_t HowDiff(string a, string b){
    size_t ans = 0;
    for(size_t i=0; i<a.size(); i++)
        ans += (a[i]==b[i]);
    return ans;
}

int main() {
    string A, B;
    cin >> A >> B;

    size_t max_l = 0;
    for(size_t i=0; i<B.size()-A.size()+1; i++){
        max_l = max(max_l, HowDiff(A, B.substr(i, A.size())));
    }
    cout << A.size()-max_l << '\n';
}