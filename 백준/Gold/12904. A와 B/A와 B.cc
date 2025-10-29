#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

	string S, T;
    cin >> S >> T;

    while (T.size() > S.size()) {
        if (T.back() == 'A') {
            T.pop_back();
        } else { // 'B'
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    cout << (T == S ? 1 : 0) << '\n';
}