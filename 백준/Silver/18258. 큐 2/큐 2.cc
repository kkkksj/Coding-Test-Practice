#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    
    int n;
    cin >> n;

    string cmd;
    int num;
    queue <int> q;
    for(int i=0; i<n; i++){
        cin >> cmd;
        if(cmd == "push"){
            cin >> num;
            q.push(num);
        }
        else if(cmd == "pop"){
            if(q.empty())
                cout << -1 << '\n';
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(cmd == "size")
            cout << q.size() << '\n';
        else if(cmd == "empty")
            cout << q.empty() << '\n';
        else if(cmd == "front"){
            if(q.empty())
                cout << -1 <<'\n';
            else
                cout << q.front() << '\n';
        }
        else{
            if(q.empty())
                cout << -1 <<'\n';
            else
                cout << q.back() << '\n';
        }
    }
}