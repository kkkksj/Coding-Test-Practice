#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std; 

string number;
string front, back, back_reverse;

int main() {
    while(1){
        cin >> number;
        if(number == "0")
            break;
        
        int len = number.length();
        if(len%2 == 0){
            front = number.substr(0, len/2);
            back = number.substr(len/2, len/2);
        }
        else{
            front = number.substr(0, len/2);
            back = number.substr(len/2 + 1, len/2);
        }
        reverse(back.begin(), back.end());
        if(front == back)
            cout << "yes" << '\n';
        else   
            cout << "no" << '\n';
    }
}