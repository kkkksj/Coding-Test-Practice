#include <string>
#include <vector>
#include <queue>

using namespace std;

void DFS(vector<vector<int>> &computers, vector<bool> &visited, int node, int n){
    visited[node] = true;
    for(int i=0; i<n; i++){
        if(visited[i] == false && computers[node][i])
            DFS(computers, visited, i, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited (n, false);
    for(int i=0; i<n; i++)
        if(visited[i] == false){
            DFS(computers, visited, i, n);
            answer++;
        }
    return answer;
}