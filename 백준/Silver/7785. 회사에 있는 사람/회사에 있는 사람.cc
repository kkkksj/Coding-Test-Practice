#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> log_map; 

    for (int i = 0; i < n; ++i) {
        string name, action;
        cin >> name >> action;
        log_map[name] = action;
    }

    for (auto it = log_map.rbegin(); it != log_map.rend(); ++it) {
        if (it->second == "enter")
            cout << it->first << '\n';
    }
}