#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string text;
    getline(cin, text);

    stack<char> st;
    bool flag = true; //뒤집어야 하는지
    for(char c : text){
        if(flag){
            if(c == '<' || c == ' '){
                while(!st.empty()){
                    cout << st.top();
                    st.pop();
                }
                cout << c;
                if(c == '<')
                    flag = false;
            }
            else
                st.push(c);
        }
        else{
            cout << c;
            if(c == '>')
                flag = true;
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}