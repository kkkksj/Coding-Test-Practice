#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPossible(vector<int> stones, int k, int m){
    int cnt = 0;
    for(int i=0; i<stones.size(); i++){
        if(stones[i] >= m)
            cnt = 0;
        else{
            if(cnt == k-1)    return false;
            else    cnt++;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int s = 1, e = *max_element(stones.begin(), stones.end());
    while(s<=e){
        int mid = (s+e)/2;
        if(IsPossible(stones, k, mid)){
            answer = mid;
            s = mid+1;
        }
        else
            e = mid - 1;
    }
    
    return answer;
}