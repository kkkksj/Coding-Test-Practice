#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool Sort(pair<string, int> a, pair<string, int> b){
    if(a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    map<string, int> list;
    string name;
    for(int i=0; i<n; i++){
        cin >> name;
        list[name]++;
    }

    vector<pair<string, int>> temp(list.begin(), list.end());
    sort(temp.begin(), temp.end(), Sort);
    cout << temp[0].first << '\n';
}