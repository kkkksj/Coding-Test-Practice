#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

bool Check(int num, vector<int>& arr) {
    for (int x : arr) {
        if (x % num == 0)
            return false;
    }

    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];

    for (int i = 1; i < arrayA.size(); i++) {
        gcdA = GCD(gcdA, arrayA[i]);
        gcdB = GCD(gcdB, arrayB[i]);
    }

    int answer = 0;

    if (Check(gcdA, arrayB))
        answer = max(answer, gcdA);

    if (Check(gcdB, arrayA))
        answer = max(answer, gcdB);

    return answer;
}