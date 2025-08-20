#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;

    while(t--){
        string cmd;
        cin >> cmd;

        int n; 
        cin >> n;

        string num_list;
        cin >> num_list;

        deque<int> dq;
        string num_s = "";
        for(int i=1; i<(int)num_list.length(); i++){
            char num = num_list[i];
            if(num == ',' || num == ']'){
                if(num_s != ""){
                    dq.push_back(stoi(num_s));
                    num_s = "";
                }
            }
            else 
                num_s += num;
        }
        bool flag = false;
        bool re = false;
        for(char c : cmd){
            if(c == 'D'){
                if(dq.empty()){
                    cout << "error" << '\n';
                    flag = true;
                    break;
                }
                else{
                    if(re)
                        dq.pop_back();
                    else
                        dq.pop_front();
                }
            }
            else
                re = !re;
        }

        if(flag == false){
            if(re)
                reverse(dq.begin(), dq.end());
            cout << '[';
            while(!dq.empty()){
                cout << dq.front();
                if(dq.size() != 1)
                    cout << ',';
                dq.pop_front();
            }
            cout << ']' << '\n';
        }
    }
}