#define _CRT_SECURE_NO_WARNINGS
#define MAXN 100000

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct INFO
{
    int start, end;

    bool operator<(const INFO& right) const {
        if (end != right.end)
            return end < right.end;

        return start < right.start;
    }
};

vector<INFO> input_list;

int main() {
    int n;
    cin >> n;

    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        input_list.push_back({ a, b });
    }

    sort(input_list.begin(), input_list.end());

    int answer = 0;
    int end_time = 0;

    for (int i = 0; i < n; i++) {
        if (input_list[i].start >= end_time) {
            answer++;
            end_time = input_list[i].end;
        }
    }

    cout << answer;

    return 0;
}