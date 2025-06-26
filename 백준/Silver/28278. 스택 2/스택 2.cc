#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, cmd;
    cin >> n;

    int num;
    stack<int> st;
    for(int i=0; i<n; i++){
        cin >> cmd;
        if(cmd == 1){
            cin >> num;
            st.push(num);
        }
        else if(cmd == 2){
            if(st.empty())
                cout << -1 << '\n';
            else{
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if(cmd == 3)
            cout << st.size() << '\n';
        else if(cmd == 4)
            cout << st.empty() << '\n';
        else{
            if(st.empty())
                cout << -1 << '\n';
            else
                cout << st.top() << '\n';
        }
    }
}