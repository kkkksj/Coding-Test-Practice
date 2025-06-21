#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string number;
    cin >> number;

    vector<string> num (number.size());
    for(size_t i=0; i<number.size(); i++)
        num[i] = number[i];
    
    sort(num.begin(), num.end());
    
    if(num[0] == "0"){
        int sum = 0;
        string ans = "";
        for(string n : num){
            sum += stoi(n);
            ans = n+ans;
        }
        if(sum%3 == 0)
            cout << ans;
        else
            cout << -1;
    }
    else
        cout << -1;
}