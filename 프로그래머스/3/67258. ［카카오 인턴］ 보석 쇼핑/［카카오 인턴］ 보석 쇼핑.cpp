#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> kinds(gems.begin(), gems.end());
    int jn = kinds.size();
    int n = gems.size();

    unordered_map<string, int> window;
    int i = 0;
    int best_len = n + 1, best_i = 0, best_j = n - 1;

    for (int j = 0; j < n; j++) {
        window[gems[j]]++;

        while ((int)window.size() == jn) {
            if (j - i + 1 < best_len) {
                best_len = j - i + 1;
                best_i = i;
                best_j = j;
            }
            window[gems[i]]--;
            if (window[gems[i]] == 0) window.erase(gems[i]);
            i++;
        }
    }

    return {best_i + 1, best_j + 1};
}