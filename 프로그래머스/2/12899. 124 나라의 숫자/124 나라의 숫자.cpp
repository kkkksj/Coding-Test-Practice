#include <string>

using namespace std;

string solution(int n) {
    string answer = "";

    while (n > 0) {
        n--;

        int remain = n % 3;

        if (remain == 0)
            answer = '1' + answer;
        else if (remain == 1)
            answer = '2' + answer;
        else
            answer = '4' + answer;

        n /= 3;
    }

    return answer;
}