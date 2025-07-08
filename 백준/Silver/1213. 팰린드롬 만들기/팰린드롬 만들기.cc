#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int MakePal(map<char, int> alphanum, int n){
    vector<char> ans (n);
    bool oddflag = false;
    int idx = 0;
    for(auto m=alphanum.begin(); m!=alphanum.end(); m++){
        if(!oddflag){
            for(int i=0; i<m->second/2; i++){
                ans[idx] = m->first;
                ans[n-1-idx] = m->first;
                idx++;
            }
            if(m->second % 2 == 1){
                if(n%2 == 1){
                    ans[n/2] = m->first;
                    oddflag = true;
                }
                else{
                    cout << "I'm Sorry Hansoo" << '\n';
                    return 0;
                }
            }
            
        }
        else{
            if(m->second % 2 == 1){ //홀수가 한 개 이상일 때는 못 만듦
                cout << "I'm Sorry Hansoo" << '\n';
                return 0;
            }
            else{
                for(int i=0; i<m->second/2; i++){
                ans[idx] = m->first;
                ans[n-1-idx] = m->first;
                idx++;
                }
            }
        }
    }
    for(char c:ans)
        cout << c;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string name;
    cin >> name;

    map<char, int> alphanum;
    for(char c : name)
        alphanum[c]++;

    int n = (int)name.size();
    
    MakePal(alphanum, n);
}