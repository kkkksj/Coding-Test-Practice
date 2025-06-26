#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool IsGoodWord(string AB){
    stack<char> st;
    for(char c : AB){
        if(st.empty() || st.top() != c)
            st.push(c);
        else
            st.pop();
    }
    if(st.empty())
        return 1;
    return 0;
}

int main() {
    int n;
    cin >> n;

    string AB;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> AB;
        if(IsGoodWord(AB))
            ans++;
    }
    cout << ans << '\n';
}