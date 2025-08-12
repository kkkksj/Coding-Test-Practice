#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

string ans_min = "";
string ans_max = "";

void FindMin(vector<char> &sign, vector<char> made, int n){
    if((int)made.size() == n+1){
        char prev = made[0];
        for(int i=0; i<n; i++){
            char now = made[i+1];
            if(sign[i] == '<'){
                if(prev > now)
                    return;
            }
            else
                if(prev < now)
                    return;
            prev = now;
        }
        for(char tmp:made)
            ans_min += tmp;
    }
    else
        for(char i='0'; i<='9'; i++)
            if(find(made.begin(), made.end(), i) == made.end()){
                made.push_back(i);
                FindMin(sign, made, n);
                if(ans_min != "")
                    return;
                made.pop_back();
            }
}

void FindMax(vector<char> &sign, vector<char> made, int n){
    if((int)made.size() == n+1){
        char prev = made[0];
        for(int i=0; i<n; i++){
            char now = made[i+1];
            if(sign[i] == '<'){
                if(prev > now)
                    return;
            }
            else
                if(prev < now)
                    return;
            prev = now;
        }
        for(char tmp:made)
            ans_max += tmp;
    }
    else
        for(char i='9'; i>='0'; i--)
            if(find(made.begin(), made.end(), i) == made.end()){
                made.push_back(i);
                FindMax(sign, made, n);
                if(ans_max != "")
                    return;
                made.pop_back();
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<char> sign(n);
    for(int i=0; i<n; i++)
        cin >> sign[i];

    vector<char> made;
    FindMin(sign, made, n);
    FindMax(sign, made, n);
    cout << ans_max << '\n' << ans_min << '\n';
}
