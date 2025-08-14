#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void Hanoi(int start, int end, int tmp, int n){
    if(n == 1){
        cout << start << ' ' << end << '\n';
        return;
    }
    Hanoi(start, tmp, end, n-1);
    cout << start << ' ' << end << '\n';
    Hanoi(tmp, end, start, n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    cout << (int)pow(2, n)-1 << '\n';
    Hanoi(1, 3, 2, n);
}