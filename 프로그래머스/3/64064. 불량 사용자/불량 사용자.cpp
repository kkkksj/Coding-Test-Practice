#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<vector<string>> result;
vector<string> selected;
vector<bool> visited;

bool isMatch(string user, string banned) {
    if (user.size() != banned.size()) {
        return false;
    }

    for (int i = 0; i < user.size(); i++) {
        if (banned[i] == '*') continue;

        if (user[i] != banned[i]) {
            return false;
        }
    }

    return true;
}

void dfs(int depth, vector<string>& user_id, vector<string>& banned_id) {
    if (depth == banned_id.size()) {
        vector<string> temp = selected;
        sort(temp.begin(), temp.end());
        result.insert(temp);
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        if (visited[i]) continue;

        if (isMatch(user_id[i], banned_id[depth])) {
            visited[i] = true;
            selected.push_back(user_id[i]);

            dfs(depth + 1, user_id, banned_id);

            selected.pop_back();
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    result.clear();
    selected.clear();
    visited.assign(user_id.size(), false);

    dfs(0, user_id, banned_id);

    return result.size();
}