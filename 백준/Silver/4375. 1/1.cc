#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

int find(string num){
    int intnum = stoi(num);
    long long ans = 1;
    int ans_n = 1;

    while(true < 10001){
        if(ans % intnum == 0)
            return ans_n;
        ans = (ans % intnum)*10 + 1;
        ans_n++;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string num;
    
    while(cin >> num){
        if(num == "1" || num == "11" || num == "111" || num == "1111")
            cout << num.size() << '\n';
        else
            cout << find(num) << '\n';
    }
}