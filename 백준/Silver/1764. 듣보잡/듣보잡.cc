#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    string name;
    vector<string> nonlisten (n);
    vector<string> nonseen (m);
    for(int i=0; i<n; i++){
        cin >> nonlisten[i];
        cin.ignore();
    }
    sort(nonlisten.begin(), nonlisten.end());

    for(int i=0; i<m; i++){
        cin >> nonseen[i];
        cin.ignore();
    }
    sort(nonseen.begin(), nonseen.end());
    
    vector<string> inter (min(n, m));
    auto i = set_intersection(nonlisten.begin(), nonlisten.end(), nonseen.begin(), nonseen.end(), inter.begin());
    inter.erase(i, inter.end());

    cout << inter.size() << '\n';
    for(string s : inter)
        cout << s << '\n';
}