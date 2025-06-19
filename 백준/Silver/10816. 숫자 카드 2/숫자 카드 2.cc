#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    signed int num;
    cin >> n;

    unordered_map<signed int, int> card;
    for(int i=0; i<n; i++){
        cin >> num;
        card[num]++;
    }
    
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> num;
        if(card.find(num) != card.end())
            cout << card[num] << ' ';
        else
            cout << 0 << ' ';
    }
}