#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> used;

    used.insert(words[0]);

    for (int i = 1; i < words.size(); i++) {
        string prev = words[i - 1];
        string now = words[i];

        bool wrongStart = prev.back() != now.front();
        bool duplicated = used.count(now) > 0;
        bool oneLetter = (now.length() == 1);

        if (wrongStart || duplicated || oneLetter) {
            int person = (i % n) + 1;
            int turn = (i / n) + 1;

            return {person, turn};
        }

        used.insert(now);
    }

    return {0, 0};
}