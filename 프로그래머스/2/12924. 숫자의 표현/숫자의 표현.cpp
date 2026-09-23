#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int s = 1;
    int e = 1;
    int sum = 1;

    while (s <= n) {
        if (sum == n) {
            answer++;
            sum -= s;
            s++;
        }
        else if (sum > n) {
            sum -= s;
            s++;
        }
        else {
            e++;
            if (e > n) 
                break;
            sum += e;
        }
    }

    return answer;
}