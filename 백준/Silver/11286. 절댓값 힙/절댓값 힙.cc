#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct CMP{
    bool operator()(int a, int b){
        if(abs(a) != abs(b))
            return abs(a) > abs(b);
        return a > b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, CMP> pq;
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        if(num == 0){
            if(pq.empty())
                cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(num);
    }
}