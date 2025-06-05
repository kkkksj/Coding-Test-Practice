#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
    int n;
    cin >> n;

    string word;
    int ans = 0;
    for(int i=0; i<n; i++){
        int alpha_cnt[26] = {0,}; 
        cin >> word;
        char before_c = '0';
        for(char c : word){
            if(before_c != c && alpha_cnt[c-'a'] == 1){
                ans--;
                break;
            }
            else if(before_c != c && alpha_cnt[c-'a'] == 0){
                before_c = c;
                alpha_cnt[c-'a'] = 1; 
            }
        }
        ans++;
    }
    cout << ans;
}