#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);

    int left = 1;
    int right = distance;

    while (left <= right) {
        int mid = (left + right) / 2;

        int removed = 0;
        int prev = 0;

        for (int rock : rocks) {
            if (rock - prev < mid) {
                removed++;
            } else {
                prev = rock;
            }
        }

        if (removed <= n) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return answer;
}