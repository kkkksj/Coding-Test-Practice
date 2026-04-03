#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int parent[1000001]; 
int visited[1000001];

void solve(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = 0;
    parent[n] = -1; 

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == 1) {
            cout << visited[1] << "\n"; 

            int temp = 1;
            vector<int> path;
            while (temp != -1) {
                path.push_back(temp);
                temp = parent[temp];
            }
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            return;
        }

        int next_ops[3];
        int count = 0;
        if (cur % 3 == 0) next_ops[count++] = cur / 3;
        if (cur % 2 == 0) next_ops[count++] = cur / 2;
        next_ops[count++] = cur - 1;

        for (int i = 0; i < count; i++) {
            int next_num = next_ops[i];

            if (next_num >= 1 && visited[next_num] == 0 && next_num != n) {
                visited[next_num] = visited[cur] + 1;
                parent[next_num] = cur; 
                q.push(next_num);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
    return 0;
}