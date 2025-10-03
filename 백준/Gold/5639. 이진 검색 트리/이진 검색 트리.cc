#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> list;

void Sol(int start, int end){
    if(start >= end)    return;
    if(start == end-1){
        cout << list[start] << '\n';
        return;
    }

    int idx = start+1;
    while(idx < end){
        if(list[start] < list[idx]) break;
        idx++;
    }

    Sol(start+1, idx);
    Sol(idx, end);

    cout << list[start] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    while(cin >> num)
        list.push_back(num);
    
    Sol(0, (int)list.size());
}