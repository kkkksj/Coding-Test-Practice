#include <string>
#include <vector>

using namespace std;

int CountOne(int num){
    int cnt = 0;
    while(num){
        if(num%2 == 1)
            cnt++;
        num /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int originone = CountOne(n);
    for(int num = n+1; num <= n*2; num++)
        if(CountOne(num) == originone){
            answer = num;
            break;
        }
    return answer;
}