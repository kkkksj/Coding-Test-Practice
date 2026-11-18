#include <string>
#include <vector>

using namespace std;

int GetBlock(long long num) {
    if (num == 1)
        return 0;

    int result = 1;

    for (long long i = 2; i * i <= num; i++) {
        if (num % i != 0)
            continue;

        long long large = num / i;

        if (large <= 10000000)
            return large;

        if (i <= 10000000)
            result = i;
    }

    return result;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (long long num = begin; num <= end; num++) 
        answer.push_back(GetBlock(num));


    return answer;
}