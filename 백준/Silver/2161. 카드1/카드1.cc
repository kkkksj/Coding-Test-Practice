#include <iostream>
#include <queue>

using namespace std;

int main() { 
    int n;
    cin >> n;

    queue<int> q;
    for(int i=1; i<n+1; i++)
        q.push(i);
    
    int num;
    while(!q.empty()){
        num = q.front();
        cout << num << ' ';
        q.pop();
        if(q.empty())
            continue;
        num = q.front();
        q.pop();
        q.push(num);
    }
}