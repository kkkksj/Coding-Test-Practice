#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string text;
    cin >> text;

    unordered_set<string> part_set;
    for(size_t i=0; i<text.size(); i++)
        for(size_t j=1; j<=text.size()-i; j++)
            part_set.insert(text.substr(i, j));
    
    cout << part_set.size();
}