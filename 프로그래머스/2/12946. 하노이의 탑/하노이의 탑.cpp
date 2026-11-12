#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void Hanoi(int n, int from, int to, int mid) {
    if (n == 1) {
        answer.push_back({from, to});
        return;
    }

    Hanoi(n - 1, from, mid, to);
    answer.push_back({from, to});
    Hanoi(n - 1, mid, to, from);
}

vector<vector<int>> solution(int n) {
    Hanoi(n, 1, 3, 2);

    return answer;
}