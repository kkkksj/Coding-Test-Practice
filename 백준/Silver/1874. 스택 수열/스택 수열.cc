#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    queue<int> ans;
    queue<int> num_s;
    int num;
    for(int i=1; i<n+1; i++){
        cin >> num;
        ans.push(num);
        num_s.push(i);
    }

    stack<int> tmp;
    vector<char> answer;
    while(!num_s.empty()){
        if(tmp.empty() || tmp.top()!=ans.front()){
            tmp.push(num_s.front());
            num_s.pop();
            answer.push_back('+');
        }
        else{
            while(!ans.empty() && !tmp.empty()){
                if(tmp.top() != ans.front())
                    break;
                tmp.pop();
                ans.pop();
                answer.push_back('-');
            }
        }
    }

    while(!ans.empty() && !tmp.empty()){
        if(tmp.top() != ans.front())
            break;
        tmp.pop();
        ans.pop();
        answer.push_back('-');
    }

    if(tmp.empty())
        for(char c : answer)
            cout << c << '\n';
    else
        cout << "NO";
}