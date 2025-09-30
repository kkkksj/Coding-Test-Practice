#include <iostream>
#include <unordered_set>
#include <cstring>

using namespace std;

unordered_set<char> none;

bool IsPossible(const string s){
    for(char c : s){
        if(none.find(c) != none.end())
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string num;  
    cin >> num;

    int m;       
    cin >> m;
    for(int i=0;i<m;i++){
        char tmp; cin >> tmp;
        none.insert(tmp);
    }

    int target = stoi(num);

    int answer = abs(target - 100);

    for (int ans = 0; ans <= 1000000; ++ans) {
        int up = target + ans;
        if (up <= 1000000) {
            string s = to_string(up);
            if (IsPossible(s)) {
                answer = min(answer, (int)s.size() + ans);
            }
        }

        int down = target - ans;
        if (down >= 0) {
            string s = to_string(down);
            if (IsPossible(s))
                answer = min(answer, (int)s.size() + ans);
        }
    }

    cout << answer << '\n';
}