#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (s < n) {
        return {-1};
    }

    int base = s / n;
    int remain = s % n;

    for (int i = 0; i < n; i++) {
        answer.push_back(base);
    }

    for (int i = n - 1; i >= n - remain; i--) {
        answer[i]++;
    }

    return answer;
}