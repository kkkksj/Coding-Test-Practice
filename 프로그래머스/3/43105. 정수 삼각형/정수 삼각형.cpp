#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int n = (int)triangle.size();
    vector<int> prev(n);
    vector<int> curr(n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            if(j==0)
                curr[j] = prev[0] + triangle[i][j];
            else if(i==j)
                curr[j] = prev[j-1] + triangle[i][j];
            else
                curr[j] = max(prev[j-1], prev[j]) + triangle[i][j];
        }
        prev= curr;
    }
    
    answer = *max_element(prev.begin(), prev.end());
    return answer;
}