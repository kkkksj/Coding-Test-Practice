#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int ans = -1;
    for (int i = 0; i < N; i++)
        if (ans < A[i].second - i)
            ans = A[i].second - i;

    cout << ans + 1;
}	