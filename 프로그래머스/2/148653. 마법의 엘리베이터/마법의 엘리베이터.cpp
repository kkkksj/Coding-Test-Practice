#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;

    while (storey > 0) {
        int now = storey % 10;
        int next = (storey / 10) % 10;

        if (now > 5) {
            answer += 10 - now;
            storey += 10 - now;
        }
        else if (now < 5) {
            answer += now;
            storey -= now;
        }
        else {
            if (next >= 5) {
                answer += 5;
                storey += 5;
            }
            else {
                answer += 5;
                storey -= 5;
            }
        }

        storey /= 10;
    }

    return answer;
}