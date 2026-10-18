#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
bool visited[8];

void dfs(int fatigue, int cnt, vector<vector<int>>& dungeons) {
    answer = max(answer, cnt);

    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i])
            continue;

        if (fatigue < dungeons[i][0])
            continue;

        visited[i] = true;
        dfs(fatigue - dungeons[i][1], cnt + 1, dungeons);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, 0, dungeons);

    return answer;
}