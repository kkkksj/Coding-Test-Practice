#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    unordered_set<int> deleted;
    for(string cmd : operations){
        string op = cmd.substr(0, 1);
        int num = stoi(cmd.substr(2, cmd.length()-2));
        
        if(op == "I"){
            max_pq.push(num);
            min_pq.push(num);
            if(deleted.find(num) != deleted.end())
                deleted.erase(num);
        }
        else{
            if(num == 1)
                while(!max_pq.empty()){
                    if(deleted.find(max_pq.top()) != deleted.end())
                        max_pq.pop();
                    else{
                        deleted.insert(max_pq.top());
                        max_pq.pop();
                        break;
                    }
                }
            else if (num == -1)
                while(!min_pq.empty()){
                    if(deleted.find(min_pq.top()) != deleted.end())
                        min_pq.pop();
                    else{
                        deleted.insert(min_pq.top());
                        min_pq.pop();
                        break;
                    }
                }
        }
    }
    
    while(!max_pq.empty()){
        if(deleted.find(max_pq.top()) != deleted.end())
            max_pq.pop();
        else
            break;
    }
    while(!min_pq.empty()){
        if(deleted.find(min_pq.top()) != deleted.end())
            min_pq.pop();
        else
            break;
    }
    
    
    if(max_pq.empty() && min_pq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }
    return answer;
}