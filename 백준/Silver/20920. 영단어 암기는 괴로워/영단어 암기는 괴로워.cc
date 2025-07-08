#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool CMP(pair<string, int> a, pair<string, int> b){
    if(a.second != b.second)
        return a.second > b.second;
    if(a.first.size() != b.first.size())
        return a.first.size() > b.first.size();
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    map<string, int> list;
    string name;
    for(int i=0; i<n; i++){
        cin >> name;
        if((int)name.size() >= m)
            list[name]++;
    }
    vector<pair<string, int>> vec_list (list.begin(), list.end());
    sort(vec_list.begin(), vec_list.end(), CMP);

    for(pair<string, int> tmp : vec_list){
        cout << tmp.first << '\n';
    }
}