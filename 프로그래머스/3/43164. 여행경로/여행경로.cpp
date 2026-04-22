#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> answer;
map<string, vector<string>> graph;
map<string, vector<bool>> used;     

bool dfs(string current, int count, int total) {
    answer.push_back(current);  
    
    if (count == total) 
        return true;
    
    if (graph.find(current) != graph.end()) {
        for (int i = 0; i < graph[current].size(); i++) {
            if (!used[current][i]) {
                used[current][i] = true;  
                
                if (dfs(graph[current][i], count + 1, total)) 
                    return true;  
                
                used[current][i] = false;  
            }
        }
    }
    
    answer.pop_back();  // 백트래킹: 현재 공항 제거
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    for (vector<string> ticket : tickets) {
        graph[ticket[0]].push_back(ticket[1]);
    }
    
    for (auto it = graph.begin(); it != graph.end(); it++) {
        sort(it->second.begin(), it->second.end());  
        used[it->first] = vector<bool>(it->second.size(), false);  
    }
    
    dfs("ICN", 0, tickets.size()); 
    
    return answer;
}