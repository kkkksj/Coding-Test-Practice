#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    deque<int> dq;
    int cmd, num;
    for(int i=0; i<n; i++){
        cin >> cmd;
        if(cmd == 1){
            cin >> num;
            dq.push_front(num);
        }
        else if(cmd == 2){
            cin >> num;
            dq.push_back(num);
        }
        else if(cmd == 3){
            if(dq.empty())
                cout << -1 << '\n';
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(cmd == 4){
            if(dq.empty())
                cout << -1 << '\n';
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(cmd == 5)
            cout << dq.size() <<'\n';
        else if(cmd == 6)
            cout << dq.empty() << '\n';
        else if(cmd == 7){
            if(dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.front() <<'\n';
        }
        else{
            if(dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.back() <<'\n';
        }  
    }
}