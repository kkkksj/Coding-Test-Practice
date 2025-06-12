#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int GetGCD(int a, int b){
    if(b == 0)
        return a;
    return GetGCD(b, a%b);
}

int main() { 
    long long num1, num2;
    cin >> num1 >> num2;
    
    cout << (num1*num2)/GetGCD(num1, num2) << '\n';
}