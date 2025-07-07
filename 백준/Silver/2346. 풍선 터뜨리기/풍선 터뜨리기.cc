#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct Info{
    int idx;
    int number;
};

void Minus(deque<Info> &dq, Info &pop){
    for(int i=1; i<-pop.number; i++){
        Info tmp = dq.back();
        dq.push_front(tmp);
        dq.pop_back();
    }
    pop = dq.back();
    dq.pop_back();
}

void Plus(deque<Info> &dq, Info &pop){
    for(int i=1; i<pop.number; i++){
        Info tmp = dq.front();
        dq.push_back(tmp);
        dq.pop_front();
    }
    pop = dq.front();
    dq.pop_front();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, num;
    cin >> n;

    deque<Info> dq;
    for(int i=1; i<n+1; i++){
        cin >> num;
        dq.push_back({i, num});
    }

    Info pop;
    pop = dq.front();
    dq.pop_front();

    while(!dq.empty()){
        cout << pop.idx << ' ';
        if(pop.number < 0)
            Minus(dq, pop);
        else   
            Plus(dq, pop);
    }
    cout << pop.idx << '\n';
}