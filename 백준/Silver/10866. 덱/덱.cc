#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    int n;
    deque<int> dq;
    cin >> n;

    string cmd;
    int num;
    for(int i=0; i<n; i++){
        cin >> cmd;
        if(cmd == "push_front"){
            cin >> num;
            dq.push_front(num);
        }
        else if(cmd == "push_back"){
            cin >> num;
            dq.push_back(num);
        }
        else if(cmd == "pop_front"){
            if(dq.empty())
                cout << -1 << '\n'; 
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(cmd == "pop_back"){
            if(dq.empty())
                cout << -1 << '\n'; 
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(cmd == "size")
            cout << dq.size() << '\n';
        else if(cmd == "empty")
            cout << dq.empty() << '\n';
        else if(cmd == "front"){
            if(dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.front() << '\n';
        }
        else{
            if(dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.back() << '\n';
        }
    }
}