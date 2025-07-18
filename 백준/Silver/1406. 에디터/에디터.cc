#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string text;
    cin >> text;

    deque<char> dq1;
    for(char c : text)
        dq1.push_back(c);

    int n;
    cin >> n;
    
    char cmd, c;
    deque<char> dq2;
    for(int i=0; i<n; i++){
        cin >> cmd;

        if(cmd == 'L'){
            if(!dq1.empty()){
                dq2.push_front(dq1.back());
                dq1.pop_back();
            }
        }
        else if(cmd == 'D'){
            if(!dq2.empty()){
                dq1.push_back(dq2.front());
                dq2.pop_front();
            }
        }
        else if(cmd == 'B'){
            if(!dq1.empty())
                dq1.pop_back();
        }
        else{
            cin >> c;
            dq1.push_back(c);
        }
    }

    while(!dq1.empty()){
        cout << dq1.front();
        dq1.pop_front();
    }
    while(!dq2.empty()){
        cout << dq2.front();
        dq2.pop_front();
    }
}