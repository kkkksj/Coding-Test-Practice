#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
int n;

void DFS(int cnt, int res, vector<int> numbers, int target){
    if(cnt == n){
        if(res == target)
            answer++;
        return;
    }
    
    DFS(cnt + 1, res-numbers[cnt], numbers, target);
    DFS(cnt + 1, res+numbers[cnt], numbers, target);
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    
    DFS(0, 0, numbers, target);
    return answer;
}