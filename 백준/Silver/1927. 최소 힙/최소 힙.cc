#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> pq;
    unsigned int num;
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