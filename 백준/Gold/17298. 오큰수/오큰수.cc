#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty()){
            if(st.top() <= arr[i])
                st.pop();
            else
                break;
        }
        
        if(st.empty())
            ans[i] = -1;
        else    
            ans[i] = st.top();
        
        st.push(arr[i]);
    }

    for(int a : ans)
        cout << a << ' ';
}