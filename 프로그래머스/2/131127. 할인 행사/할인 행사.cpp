#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    unordered_map<string, int> target;

    for (int i = 0; i < want.size(); i++) 
        target[want[i]] = number[i];

    for (int start = 0; start + 10 <= discount.size(); start++) {
        unordered_map<string, int> cnt;

        for (int i = start; i < start + 10; i++) 
            cnt[discount[i]]++;

        bool possible = true;

        for (int i = 0; i < want.size(); i++) {
            if (cnt[want[i]] != number[i]) {
                possible = false;
                break;
            }
        }

        if (possible) 
            answer++;
    }

    return answer;
}