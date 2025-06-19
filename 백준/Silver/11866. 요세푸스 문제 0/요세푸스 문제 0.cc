#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    queue<int> q;
    for(int j=1; j<n+1; j++)
        q.push(j);
    
    int i = 1;
    cout << '<';
    while(q.size() > 1){
        if(i==m){
            cout << q.front() << ", ";
            q.pop();
            i = 1;
        }
        else{
            int num =  q.front();
            q.pop();
            q.push(num);
            i++;
        }
    }
    cout << q.front() << '>';
}