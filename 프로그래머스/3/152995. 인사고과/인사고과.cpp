#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CMP(vector<int> a, vector<int> b) {
    if (a[0] != b[0]) 
        return a[0] > b[0]; // 0인덱스는 내림차순
    return a[1] < b[1];     // 1인덱스는 오름차순
}

int solution(vector<vector<int>> scores) {
    int answer = 0;

    int target0 = scores[0][0];
    int target1 = scores[0][1];

    sort(scores.begin(), scores.end(), CMP);

    int rank = 1;
    int max1 = -1;
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i][1] < max1) { // 두 점수 모두 다른 사람보다 낮아
            if (scores[i][0] == target0 && scores[i][1] == target1)
                // 원호 점수면 -1
                return -1;
            continue;
        }

        max1 = max(max1, scores[i][1]);

        if (scores[i][0] + scores[i][1] > target0 + target1)
            rank++; // 원호보다 합이 큰 사람이면 원호 랭크 떨어짐 
    }

    return rank;
}