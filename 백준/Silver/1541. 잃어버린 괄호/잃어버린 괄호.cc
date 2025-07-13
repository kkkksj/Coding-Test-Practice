#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int Minimum(queue<char> &plusminus, queue<int> &num_q){
    char pm;
    int num = num_q.front();
    num_q.pop();
    vector<int> minus_list;

    if(num_q.empty())
        minus_list.push_back(num);
    else
        while(!num_q.empty()){
            pm = plusminus.front();
            plusminus.pop();

            if(pm == '-'){
                minus_list.push_back(num);
                num = num_q.front();
                num_q.pop();
            }
            else{
                num += num_q.front();
                num_q.pop();
            }
            if(num_q.empty())
                minus_list.push_back(num);
        }

    int ans = minus_list[0];
    for(size_t i=1; i<minus_list.size(); i++)
        ans -= minus_list[i];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string text;
    cin >> text;

    string s_num = "";
    queue<char> plusminus;
    queue<int> num_q;
    for(char c : text){
        if(c == '-' || c == '+'){
            plusminus.push(c);
            num_q.push(stoi(s_num));
            s_num = "";
        }
        else
            s_num += c;
    }
    num_q.push(stoi(s_num));

    cout << Minimum(plusminus, num_q) << '\n';
}