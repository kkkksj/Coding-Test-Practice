#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;

    string text;
    deque<char> left_dq;
    deque<char> right_dq;
    for(int i=0; i<t; i++){
        cin >> text;
        
        for(char c : text){
            if(c == '<'){
                if(left_dq.size()){
                    right_dq.push_front(left_dq.back());
                    left_dq.pop_back();
                }
            }
            else if(c == '>'){
                if(right_dq.size()){
                    left_dq.push_back(right_dq.front());
                    right_dq.pop_front();
                }
            }
            else if(c == '-'){
                if(left_dq.size())
                    left_dq.pop_back();
            }
            else
                left_dq.push_back(c);
        }
        while(left_dq.size()){
            cout << left_dq.front();
            left_dq.pop_front();
        }
        while(right_dq.size()){
            cout << right_dq.front();
            right_dq.pop_front();
        }
        cout << '\n';
    }
}