#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int n = (int)routes.size();
    int answer = 0;
    sort(routes.begin(), routes.end());
    
    int start = routes[0][1];
    
    for(int i=1; i<n; i++){
        if(routes[i][1]<start)
            start = routes[i][1];
        else if(routes[i][0]>start){
            answer++;
            start = routes[i][1];
        }
    }
    return answer+1;
}