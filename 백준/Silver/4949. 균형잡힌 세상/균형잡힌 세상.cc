#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string IsBalanced(string t){
    stack<char> s;
    for(char c : t){
        if(c == '(' || c == ')' || c == '[' || c == ']'){
            if(s.empty())
                s.push(c);
            else{
                if((s.top() == '(' && c == ')') || (s.top() == '[' && c == ']'))
                    s.pop();
                else
                    s.push(c);
            }
        }
    }
    if(s.empty())
        return "yes";
    else
        return "no";
}

int main() {
    string text;
    while(1){
        getline(cin, text);
        if(text == ".")
            break;
        cout << IsBalanced(text) << '\n';
    }
}