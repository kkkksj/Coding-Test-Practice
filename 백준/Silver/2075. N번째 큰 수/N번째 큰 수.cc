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

    priority_queue<int, vector<int>, greater<int>> pq;
    int num;
    for(int i=0; i<n*n; i++){
        cin >> num;
        pq.push(num);

        if((int)pq.size() > n)  //n보다 많이 넣은 다음에 제일 작은 값을 빼기
            pq.pop();
    }

    cout << pq.top();
}