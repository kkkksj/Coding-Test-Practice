#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> arr;

struct CMP{
    bool operator()(const int a, const int b) const{
        if(arr[a] != arr[b])
            return arr[a] < arr[b];  
        return a > b;  
    }
};

struct Info{
    int total;
    priority_queue<int, vector<int>, CMP> pq;
};

int n;
map<string, Info> dic;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    n = genres.size();
    arr = plays;  
    
    for(int i = 0; i < n; i++){
        string genre = genres[i];
        int p = plays[i];
        
        dic[genre].total += p;
        dic[genre].pq.push(i);        
    }
    
    vector<pair<int, string>> genreList;  
    for(auto& p : dic){
        genreList.push_back({p.second.total, p.first});
    }
    sort(genreList.begin(), genreList.end(), greater<pair<int, string>>());
    
    for(auto& [total, genre] : genreList){
        int cnt = 0;
        while(!dic[genre].pq.empty() && cnt < 2){
            answer.push_back(dic[genre].pq.top());
            dic[genre].pq.pop();
            cnt++;  
        }
    }
    
    return answer;
}