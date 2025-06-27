#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool Sort(pair<signed long long, int> a, pair<signed long long, int> b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n; 

    signed long long num;
    map<signed long long, int> card;
    for(int i=0; i<n; i++){
        cin >> num;
        card[num]++;
    }

    vector<pair<signed long long, int>> vec_care (card.begin(), card.end());
    sort(vec_care.begin(), vec_care.end(), Sort);

    cout << vec_care[0].first << '\n';
}