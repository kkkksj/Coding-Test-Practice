#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;

    string vowel = "AEIOU";
    int weight[5] = {781, 156, 31, 6, 1};

    for (int i = 0; i < word.size(); i++) {
        int idx = vowel.find(word[i]);

        answer += idx * weight[i] + 1;
    }

    return answer;
}