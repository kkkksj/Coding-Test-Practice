#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;

void Combi(vector<int> &ans, int n){
    if((int)ans.size() == n){
        for(int tmp : ans)
            cout << tmp << ' ';
        cout << '\n';
    }
    else
        for(int num=1; num<n+1; num++)
            if(find(ans.begin(), ans.end(), num) == ans.end()){
                ans.push_back(num);
                Combi(ans, n);
                ans.pop_back();
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> ans;
    Combi(ans, n);
}