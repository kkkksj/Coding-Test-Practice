#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int idx = 1;
    int num;
    stack<int> st;
    for(int i=0; i<n; i++){
        cin >> num;
        if(num == idx)
            idx++;
        else if(!st.empty() && st.top() == idx){
            while(!st.empty() && st.top()==idx){
                st.pop();
                idx++;
            }
            if(idx != num)
                st.push(num);
            else
                idx++;
        }
        else   
            st.push(num);
    }

    while(!st.empty()){
        if(st.top() != idx){
            cout << "Sad" << '\n';
            break;
        }
        st.pop();
        idx++;
    }

    if(st.empty())
        cout << "Nice" << '\n';
    
}