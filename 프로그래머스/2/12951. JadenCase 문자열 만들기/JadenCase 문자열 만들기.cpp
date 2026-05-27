#include <string>

using namespace std;

string solution(string s) {
    bool isFirst = true;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            isFirst = true;
        }
        else {
            if (isFirst) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[i] = s[i] - 'a' + 'A';
                }
                isFirst = false;
            }
            else {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = s[i] - 'A' + 'a';
                }
            }
        }
    }

    return s;
}