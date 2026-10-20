#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(long long a, long long b) {
        return a > b;
    }
};

int solution(vector<int> scoville, int K) {
    priority_queue<long long, vector<long long>, cmp> pq;

    for (int s : scoville) 
        pq.push(s);

    int answer = 0;

    while (pq.size() >= 2 && pq.top() < K) {
        long long first = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();

        pq.push(first + second * 2);
        answer++;
    }

    if (pq.top() < K)
        return -1;

    return answer;
}