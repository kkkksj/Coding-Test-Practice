#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    long long cnt[1001] = {0};

    sort(weights.begin(), weights.end());

    for (int w : weights) {
        answer += cnt[w];

        if (w % 2 == 0)
            answer += cnt[w / 2];

        if (w * 2 % 3 == 0)
            answer += cnt[w * 2 / 3];

        if (w * 3 % 4 == 0)
            answer += cnt[w * 3 / 4];

        cnt[w]++;
    }

    return answer;
}