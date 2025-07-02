#include <iostream>
#include <algorithm>
#include <deque>
#include <unordered_map>
using namespace std;

bool IsThereBig(deque<pair<int, int>> &dq, pair<int, int> top){
    for(pair<int, int> tmp : dq){
        if(tmp.second > top.second){
            dq.push_back(top);
            return 1;
        }
    }
    return 0;
}

int PrintTime(deque<pair<int, int>> &dq, int m){
    pair<int, int> top;
    int ans = 1;
    while(!dq.empty()){
        top = dq.front();
        dq.pop_front();
        if(!IsThereBig(dq, top)){
            if(top.first == m)
                return ans;
            else
                ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n, m;
        cin >> n >> m;

        deque<pair<int, int>> dq;
        int num;
        for(int k=0; k<n; k++){
            cin >> num;
            dq.push_back({k, num});
        }
        cout << PrintTime(dq, m) << '\n';
    }
}