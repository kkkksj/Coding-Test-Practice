#include <iostream>

using namespace std;

void Hanoi(int n, int from, int to, int mid) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    Hanoi(n - 1, from, mid, to);

    cout << from << ' ' << to << '\n';

    Hanoi(n - 1, mid, to, from);
}

int main() {
    int n;
    cin >> n;

    int cnt = 1;

    for (int i = 0; i < n; i++)
        cnt *= 2;

    cout << cnt - 1 << '\n';

    Hanoi(n, 1, 3, 2);

    return 0;
}