#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool IsRight(string s){
    stack<char> st;
    for(char c : s){
        if(!st.empty() && (st.top() == '(' && c == ')'))
            st.pop();
        else
            st.push(c);
    }
    if(st.empty())
        return true;
    return false;
}

bool solution(string s)
{
    bool answer = IsRight(s);

    return answer;
}   