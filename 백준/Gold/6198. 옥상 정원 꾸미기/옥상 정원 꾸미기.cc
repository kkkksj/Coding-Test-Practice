#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
   
    int n;
    cin >> n;
    
    int h;
    long long ans = 0;
    stack<int> st;
    for(int i=0; i<n; i++){
        cin >> h;
        
        if(st.empty())
            st.push(h);
        
        while(!st.empty() && st.top()<=h)
            st.pop();
        
        ans += st.size();

        st.push(h);
    }

    cout << ans << '\n';
}