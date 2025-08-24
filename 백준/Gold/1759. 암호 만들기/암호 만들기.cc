#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> arr;

void Combi(vector<char> &ans, int vowel_cnt, int cons_cnt){
    if((int)ans.size() == l && vowel_cnt > 0 && cons_cnt > 1){
        for(char c : ans)
            cout << c;
        cout << '\n';
    }
    else{
        for(char c : arr){
            if(ans.empty() || ans[ans.size()-1] < c){
                ans.push_back(c);
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                    Combi(ans, vowel_cnt+1, cons_cnt);
                else
                    Combi(ans, vowel_cnt, cons_cnt+1);
                ans.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> l >> c;
    
    arr.resize(c);
    for(int i=0; i<c; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    vector<char> ans;
    Combi(ans, 0, 0);
}