#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Group {
    int dia;
    int iron;
    int stone;
};

bool cmp(Group a, Group b) {
    int scoreA = a.dia * 25 + a.iron * 5 + a.stone;
    int scoreB = b.dia * 25 + b.iron * 5 + b.stone;

    return scoreA > scoreB;
}

int solution(vector<int> picks, vector<string> minerals) {
    int totalPick = picks[0] + picks[1] + picks[2];
    int maxMineral = totalPick * 5;

    int size = min((int)minerals.size(), maxMineral);

    vector<Group> groups;

    for (int i = 0; i < size; i += 5) {
        Group group = {0, 0, 0};

        for (int j = i; j < i + 5 && j < size; j++) {
            if (minerals[j] == "diamond")
                group.dia++;
            else if (minerals[j] == "iron")
                group.iron++;
            else
                group.stone++;
        }

        groups.push_back(group);
    }

    sort(groups.begin(), groups.end(), cmp);

    int answer = 0;
    int idx = 0;

    for (int i = 0; i < picks[0]; i++) {
        if (idx >= groups.size())
            break;

        answer += groups[idx].dia;
        answer += groups[idx].iron;
        answer += groups[idx].stone;

        idx++;
    }

    for (int i = 0; i < picks[1]; i++) {
        if (idx >= groups.size())
            break;

        answer += groups[idx].dia * 5;
        answer += groups[idx].iron;
        answer += groups[idx].stone;

        idx++;
    }

    for (int i = 0; i < picks[2]; i++) {
        if (idx >= groups.size())
            break;

        answer += groups[idx].dia * 25;
        answer += groups[idx].iron * 5;
        answer += groups[idx].stone;

        idx++;
    }

    return answer;
}