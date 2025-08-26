#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
vector<int> cnts;

int BFS(int start, int goal,  vector<int> &num_list){
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int num : num_list){
            if(now+num > goal)
                continue;
            if(cnts[now+num] == -1 || cnts[now] + 1 < cnts[now+num]){
                cnts[now+num] = cnts[now] + 1;
                q.push(now+num);
            }
        }
    }
    return cnts[goal];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> num_list (n);
    int start = 100000;
    cnts.resize(k+1, -1);
    for(int i=0; i<n; i++){
        cin >> num_list[i];
        q.push(num_list[i]);
        cnts[num_list[i]] = 1;
    }

    cout << BFS(start, k, num_list) << '\n';
}