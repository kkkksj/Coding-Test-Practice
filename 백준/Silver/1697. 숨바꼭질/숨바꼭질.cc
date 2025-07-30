#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, k;

int Search(){
    unordered_map<int, int> times;
    times[n] = 0;

    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int pos = q.front();
        q.pop();

        if(pos == k)
            return times[k];

        if(pos-1 >= 0)
            if(times.find(pos-1) == times.end()){
                times[pos-1] = times[pos]+1;
                q.push(pos-1);
            }
        if(times.find(pos+1) == times.end()){
            times[pos+1] = times[pos]+1;
            q.push(pos+1);
        }
        if(pos*2 <k*2)
            if(times.find(pos*2) == times.end()){
                times[pos*2] = times[pos]+1;
                q.push(pos*2);
            }        
    }

    return times[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    cout << Search() << '\n';
}   