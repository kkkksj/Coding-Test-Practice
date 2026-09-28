#include <iostream>
#include <string>
#include <stack>

using namespace std;

int IsRight(string s){
    stack<char> st;    
    
    for(char c : s){
        if(st.empty() || st.top() != c){
            st.push(c);
        }
        else
            st.pop();
    }
    
    if(st.empty())
        return 1;
    return 0;
}

int solution(string s)
{
    int answer = IsRight(s);    
    
    return answer;
}