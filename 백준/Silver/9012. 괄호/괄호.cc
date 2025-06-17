#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool IsVPS(string input){
    stack<char> s;
    for(char c : input){
        if(s.empty())
            s.push(c);
        else{
            if((s.top() == '(' and c == ')'))
                s.pop();
            else
                s.push(c);
        }
    }
    if(s.empty())
        return 1;
    else
        return 0;
}

int main() { 
    int n;
    cin >> n;
    cin.ignore();

    string input;
    for(int i=0; i<n; i++){
        getline(cin, input);
        if(IsVPS(input))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}