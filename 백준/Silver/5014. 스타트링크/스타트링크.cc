#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int BFS(int f, int s, int g, int u, int d){
    vector<long long> dist (f+1, -1);
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int floor = q.front();
        q.pop();

        if(floor == g)
            return dist[floor];

        long long up_floor = floor + u;
        long long down_floor = floor - d;
        if(up_floor < f+1 && dist[up_floor] == -1){
            dist[up_floor] = dist[floor] + 1;
            q.push(up_floor);
        }
        if(down_floor > 0 && dist[down_floor] == -1){
            dist[down_floor] = dist[floor] + 1;
            q.push(down_floor);
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    int ans = BFS(f, s, g, u, d);
    if(ans == -1)
        cout << "use the stairs" << '\n';
    else
        cout << ans << '\n';
}