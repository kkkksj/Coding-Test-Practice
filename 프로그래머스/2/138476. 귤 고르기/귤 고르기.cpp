#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> counts;
    for(int t : tangerine)
        counts[t]++;
    
    vector<int> counts_vec;
    for(auto it : counts)
        counts_vec.push_back(it.second);
    
    sort(counts_vec.begin(), counts_vec.end(), greater<int>());
    
    for(int c : counts_vec){
        k-=c;
        answer++;
        
        if(k<=0)
            break;
    }
    
    return answer;
}