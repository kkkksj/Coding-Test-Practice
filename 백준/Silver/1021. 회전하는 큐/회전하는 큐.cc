#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int PopFront(deque<int> dq, int num){
    int cnt = 0;
    while(1){
        int top = dq.front();
        if(top == num)
            return cnt;
        dq.pop_front();
        dq.push_back(top);
        cnt++;
    }
}

int PopBack(deque<int> dq, int num){
    int cnt = 0;
    while(1){
        if(dq.front() == num)
            return cnt;
        int back = dq.back();
        dq.pop_back();
        dq.push_front(back);
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    deque<int> dq;
    for(int i=1; i<n+1; i++)
        dq.push_back(i);

    int num;
    int front_cnt, back_cnt;
    int ans = 0;
    for(int i=0; i<m; i++){
        cin >> num;
        front_cnt = PopFront(dq, num);
        back_cnt = PopBack(dq, num);
        if(front_cnt <= back_cnt){
            for(int j=0; j<front_cnt; j++){
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp); 
            }
            ans += front_cnt;
        }
        else{
            for(int j=0; j<back_cnt; j++){
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp); 
            }
            ans += back_cnt;
        }
        dq.pop_front();
    }
    cout << ans << '\n';
}