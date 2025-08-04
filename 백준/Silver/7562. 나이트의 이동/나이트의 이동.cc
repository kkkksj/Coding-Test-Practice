#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct POINT
{
    int i;
    int j;
};


int BFS(int n, int si, int sj, int ei, int ej){
    queue<POINT> q;
    q.push({si, sj});

    vector<vector<int>> visited(n, vector<int> (n, 0));
    visited[si][sj] = 0;

    vector<int> i_list = {-1, -2, -2, -1, 1, 2, 2, 1};
    vector<int> j_list = {-2, -1, 1, 2, 2, 1, -1, -2};

    while(!q.empty()){
        int now_i = q.front().i;
        int now_j = q.front().j;
        q.pop();

        if(now_i == ei && now_j == ej)
            return visited[ei][ej];
        
        for(int i=0; i<8; i++){
            int next_i = now_i + i_list[i];
            int next_j = now_j + j_list[i];

            if((next_i >= 0 && next_i < n) && (next_j >= 0 && next_j < n))
                if(visited[next_i][next_j] == 0){
                    visited[next_i][next_j] = visited[now_i][now_j] + 1;
                    q.push({next_i, next_j});
                }
        }
    }

    return visited[ei][ej];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        int si, sj, ei, ej;
        cin >> si >> sj >> ei >> ej;

        cout << BFS(n, si, sj, ei, ej) << '\n';
    }
}