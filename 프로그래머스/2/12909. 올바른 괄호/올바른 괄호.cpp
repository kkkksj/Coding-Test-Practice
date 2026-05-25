#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool IsRight(string str){
    stack<char> st;
    for(char s : str){
        if(!st.empty() && (st.top() == '(' && s == ')'))
            st.pop();
        else
            st.push(s);
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