#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    long long rr1 = r1;
    long long rr2 = r2;

    rr1 *= rr1;
    rr2 *= rr2;

    for (long long x = 1; x <= r2; x++) {
        long long max_y = sqrt(rr2 - x * x);

        long long value = rr1 - x * x;
        long long min_y = 0;

        if (value > 0)
            min_y = ceil(sqrt(value));

        answer += max_y - min_y + 1;
    }

    return answer * 4;
}