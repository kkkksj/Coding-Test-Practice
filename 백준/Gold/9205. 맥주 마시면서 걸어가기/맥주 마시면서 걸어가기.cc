#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int Distance(int x, int y, int i, int j){
    return abs(x-i) + abs(y-j);
}

bool BFS(int n, pair<int, int> home, pair<int, int> goal, vector<pair<int, int>> store){
    vector<bool> visited (n, false);
    queue<pair<int, int>> q;
    q.push({home.first, home.second});

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        if(Distance(goal.first, goal.second, i, j) <= 1000)
            return 1;
        for(int d=0; d<n; d++){
            if(visited[d])
                continue;
            if(Distance(store[d].first, store[d].second, i, j) <= 1000){
                visited[d] = true;
                q.push({store[d].first, store[d].second});
            }
        }
    }

    return 0;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        pair<int, int> home, goal;
        vector<pair<int, int>> store(n);

        cin >> home.first >> home.second;
        for(int i=0; i<n; i++)
            cin >> store[i].first >> store[i].second;
        cin >> goal.first >> goal.second;

        if(BFS(n, home, goal, store))
            cout << "happy" << '\n';
        else
            cout << "sad" << '\n';
    }
}