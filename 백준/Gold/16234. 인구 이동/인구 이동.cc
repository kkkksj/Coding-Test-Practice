#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

int n, l , r;
vector<vector<int>> people;
vector<vector<int>> uni;
unordered_map<int, int> new_people;
bool flag = false;

vector<int> i_list = {-1, 1, 0, 0};
vector<int> j_list = {0, 0, -1, 1};

void BFS(int i, int j, int num){
    queue<pair<int, int>> q;
    uni[i][j] = num;
    q.push({i, j});

    int cnt_people = 0;
    int sum_people = 0;

    while(!q.empty()){
        int now_i = q.front().first;
        int now_j = q.front().second;
        q.pop();

        cnt_people++;
        sum_people += people[now_i][now_j];

        for(int d=0; d<4; d++){
            int next_i = now_i + i_list[d];
            int next_j = now_j + j_list[d];
            
            if(next_i<0 || next_i>=n || next_j<0 || next_j>=n || uni[next_i][next_j]!=-1)
                continue;
            
            int gap = abs(people[now_i][now_j] - people[next_i][next_j]);
            if(gap >= l && gap <= r){
                uni[next_i][next_j] = num;
                q.push({next_i, next_j});
                flag = true;
            }
        }
    }
    new_people[num] = sum_people/cnt_people;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;
    people.assign(n, vector<int> (n));
    uni.assign(n, vector<int> (n, -1));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> people[i][j];

    int ans = 0;
    while(true){
        new_people.clear();
        flag = false;
        int group_num = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(uni[i][j] == -1){
                    BFS(i, j, group_num);
                    group_num++;
                }
        
        if(flag == false)  break;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                int num = uni[i][j];
                if(num == -1)   continue;

                uni[i][j] = -1;
                people[i][j] = new_people[num];
            }
        ans++;
    }

    cout << ans << '\n';
}