#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int target_col;

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[target_col] != b[target_col])
        return a[target_col] < b[target_col];

    return a[0] > b[0];
}

int XOR(int a, int b) {
    int result = 0;
    int bit = 1;

    while (a > 0 || b > 0) {
        int abit = a & 1;
        int bbit = b & 1;

        if (abit != bbit)
            result += bit;

        a >>= 1;
        b >>= 1;
        bit <<= 1;
    }

    return result;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    target_col = col - 1;

    sort(data.begin(), data.end(), cmp);

    int answer = 0;

    for (int i = row_begin - 1; i < row_end; i++) {
        int sum = 0;

        for (int x : data[i]) 
            sum += x % (i + 1);

        answer = XOR(answer, sum);
    }

    return answer;
}