#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int n, int k){
    vector<int> dist(100001, -1);
    dist[n] = 0;

    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == k)
            return dist[k];

        if(now*2 < 100001)
            if(dist[now*2]==-1){
                dist[now*2] = dist[now];
                q.push(now*2);
            }
        if(now-1 > -1)
            if(dist[now-1]==-1){
                dist[now-1] = dist[now]+1;
                q.push(now-1);
            }
        if(now+1 < 100001)
            if(dist[now+1]==-1){
                dist[now+1] = dist[now]+1;
                q.push(now+1);
            }
    }
    return dist[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    cout << BFS(n, k) << '\n';
}