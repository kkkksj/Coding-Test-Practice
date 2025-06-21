#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string number;
    cin >> number;

    vector<char> num(number.size());
    for(size_t i=0; i<number.size(); i++)
        num[i] = number[i];
        
    sort(num.rbegin(), num.rend());

    if(num.back() == '0') {
        int sum = 0;
        for(char c : num)
            sum += int(c - '0');
        if(sum % 3 == 0)
            for(char c : num)
                cout << c;
        else
            cout << -1;
    }
    else
        cout << -1;
}