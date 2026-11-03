#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<long long> q1;
    queue<long long> q2;

    long long sum1 = 0;
    long long sum2 = 0;

    for (int x : queue1) {
        q1.push(x);
        sum1 += x;
    }

    for (int x : queue2) {
        q2.push(x);
        sum2 += x;
    }

    long long total = sum1 + sum2;

    if (total % 2 != 0)
        return -1;

    long long target = total / 2;

    int answer = 0;
    int limit = (queue1.size() + queue2.size()) * 2;

    while (answer <= limit) {
        if (sum1 == target)
            return answer;

        if (sum1 > target) {
            long long x = q1.front();
            q1.pop();

            sum1 -= x;
            sum2 += x;

            q2.push(x);
        }
        else {
            long long x = q2.front();
            q2.pop();

            sum2 -= x;
            sum1 += x;

            q1.push(x);
        }

        answer++;
    }

    return -1;
}