#include <string>

#define MAXN 10

using namespace std;

bool visited[MAXN+1][MAXN+1][MAXN+1][MAXN+1];
int i_list[4] = {-1, 1, 0, 0}; //위 아래 왼 오
int j_list[4] = {0, 0, -1, 1};

int solution(string dirs) {
    int answer = 0;
    int nowi = 5, nowj = 5;
    int dir, nexti, nextj;
    
    for(char c : dirs){
        if(c == 'U')
            dir = 0;
        else if(c == 'D')
            dir = 1;
        else if(c == 'L')
            dir = 2;
        else
            dir = 3;
        
        nexti = nowi + i_list[dir];
        nextj = nowj + j_list[dir];
        
        if(nexti < 0 || nexti > MAXN || nextj < 0 || nextj > MAXN)
            continue;
        
        if(!visited[nowi][nowj][nexti][nextj] && !visited[nexti][nextj][nowi][nowj]){
            answer += 1;
            visited[nowi][nowj][nexti][nextj] = true;
        }
        
        nowi = nexti;
        nowj = nextj;
    }
    
    return answer;
}