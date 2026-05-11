#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int open, int close, int n) {
    if (open == n && close == n) {
        answer++;
        return;
    }

    if (open < n) 
        dfs(open + 1, close, n);

    if (close < open) 
        dfs(open, close + 1, n);
}

int solution(int n) {
    dfs(0, 0, n);
    return answer;
}