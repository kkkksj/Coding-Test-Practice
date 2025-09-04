#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Find(string cmd){
    stack<char> st;
    int ans = 0;
    int pre = 1;
    for(int i=0; i<(int)cmd.length(); i++){
        char c = cmd[i];
        if(c == '('){
            st.push('(');
            pre *= 2;
        }
        else if(c == '['){
            st.push('[');
            pre *= 3;
        }
        else if(c == ')'){
            if(st.empty() || st.top() == '['){
                cout << 0;
                return;
            }
            if(cmd[i-1] == '(')
                ans += pre;
            pre /= 2;
            st.pop();
        }
        else if(c == ']'){
            if(st.empty() || st.top() == '('){
                cout << 0;
                return;
            }
            if(cmd[i-1] == '[')
                ans += pre;
            pre /= 3;
            st.pop();
        }
    }
    if(!st.empty()){
        cout << 0;
        return;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string cmd;
    cin >> cmd;

    Find(cmd);
}