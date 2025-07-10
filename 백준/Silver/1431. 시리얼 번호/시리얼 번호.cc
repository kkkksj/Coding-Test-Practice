#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool CMP(string a, string b){
    if(a.size() != b.size())
        return a.size() < b.size();
    int a_sum = 0;
    int b_sum = 0;
    for(char c:a)
        if('0' <= c && c <= '9')
            a_sum += (c-'0');
    for(char c:b)
        if('0' <= c && c <= '9')
            b_sum += (c-'0');
    if(a_sum != b_sum)
        return a_sum < b_sum;
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<string> serial_num (n);
    for(int i=0; i<n; i++)
        cin >> serial_num[i];

    sort(serial_num.begin(), serial_num.end(), CMP);
    
    for(string tmp : serial_num)
        cout << tmp << '\n';
}