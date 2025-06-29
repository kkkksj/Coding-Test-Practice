#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        unordered_set<int> note1;
        int num;
        for(int j=0; j<n; j++){
            cin >> num;
            note1.insert(num);
        }

        int m;
        cin >> m;
        for(int j=0; j<m; j++){
            cin >> num;
            if(note1.find(num) == note1.end())
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
    }
}