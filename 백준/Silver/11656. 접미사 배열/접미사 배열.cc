#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    string text;
    cin >> text;

    vector<string> dic (text.size());
    for(size_t i=0; i<text.size(); i++){
        dic[i] = text.substr(i);
    }

    sort(dic.begin(), dic.end());

    for(string t : dic)
        cout << t << '\n';
}