#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    vector<int> leftCnt(10001, 0);
    vector<int> rightCnt(10001, 0);

    int leftKind = 0;
    int rightKind = 0;

    for (int t : topping) {
        if (rightCnt[t] == 0)
            rightKind++;

        rightCnt[t]++;
    }

    for (int i = 0; i < topping.size() - 1; i++) {
        int t = topping[i];

        if (leftCnt[t] == 0)
            leftKind++;

        leftCnt[t]++;

        rightCnt[t]--;

        if (rightCnt[t] == 0)
            rightKind--;

        if (leftKind == rightKind)
            answer++;
    }

    return answer;
}