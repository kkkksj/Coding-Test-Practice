#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    long long dd = d;
    dd *= d;

    for (long long x = 0; x <= d; x += k) {
        long long remain = dd - x * x;
        long long max_y = sqrt(remain);

        answer += max_y / k + 1;
    }

    return answer;
}