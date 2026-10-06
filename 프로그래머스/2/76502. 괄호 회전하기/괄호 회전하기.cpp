#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') 
            st.push(ch);
        else {
            if (st.empty()) return false;

            if (ch == ')' && st.top() != '(') return false;
            if (ch == ']' && st.top() != '[') return false;
            if (ch == '}' && st.top() != '{') return false;

            st.pop();
        }
    }

    return st.empty();
}

int solution(string s) {
    int answer = 0;
    int len = s.size();

    for (int i = 0; i < len; i++) {
        string rotated = s.substr(i) + s.substr(0, i);

        if (isValid(rotated)) 
            answer++;
    }

    return answer;
}