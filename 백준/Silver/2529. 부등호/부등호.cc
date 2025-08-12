#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

string ans_min = "";
string ans_max = "";

void FindMin(vector<char> &sign, vector<char> made, int n, vector<bool> &visited){
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
            if(visited[i-'0'] == false){
                made.push_back(i);
                visited[i-'0'] = true;
                FindMin(sign, made, n, visited);
                if(ans_min != "")
                    return;
                made.pop_back();
                visited[i-'0'] = false;
            }
}

void FindMax(vector<char> &sign, vector<char> made, int n, vector<bool> &visited){
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
            if(visited[i-'0'] == false){
                made.push_back(i);
                visited[i-'0'] = true;
                FindMax(sign, made, n, visited);
                if(ans_max != "")
                    return;
                made.pop_back();
                visited[i-'0'] = false;
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

    vector<bool> visited1(10, false);
    vector<char> made;
    FindMin(sign, made, n, visited1);
    vector<bool> visited2(10, false);
    FindMax(sign, made, n, visited2);
    cout << ans_max << '\n' << ans_min << '\n';
}
