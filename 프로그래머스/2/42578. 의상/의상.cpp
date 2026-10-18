#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> cnt;

    for (auto cloth : clothes) 
        cnt[cloth[1]]++;

    int answer = 1;

    for (auto c : cnt) 
        answer *= (c.second + 1);

    return answer - 1;
}