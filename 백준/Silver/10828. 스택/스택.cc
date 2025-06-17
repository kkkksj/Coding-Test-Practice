#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() { 
    int t;
    cin >> t;

    string cmd;
    int n;
    stack<int> s;
    for(int i=0; i<t; i++){
        cin >> cmd;

        if(cmd == "push"){
            cin >> n;
            s.push(n);
        }
        else if(cmd == "pop"){
            if(s.empty())
                cout << -1 << '\n';
            else{
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(cmd == "size")
            cout << s.size() << '\n';
        else if(cmd == "empty")
            cout << s.empty() << '\n';
        else{
            if(s.empty())
                cout << -1 << '\n';
            else
                cout << s.top() << '\n';
        }
    }
}