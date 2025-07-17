#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string text;
    cin >> text;

    stack<char> st;
    int ans = 0;
    for(size_t i=0; i<text.size(); i++){
        if(text[i] == '(')
            st.push(text[i]);
        else{
            st.pop();
            if(text[i-1] == '(')
                ans += (int)st.size();
            else
                ans += 1;
        }
    }

    cout << ans << '\n';
}