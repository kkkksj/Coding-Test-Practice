#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    int n;
    for(int i=0; i<t; i++){
        cin >> n;
        map<string, int> clothes;
        for(int j=0; j<n; j++){
            string type, name;
            cin >> name >> type;
            clothes[type]++;  
        }
        int ans = 1;
        vector<pair<string, int>> clothes_vec (clothes.begin(), clothes.end());
        for(pair<string, int> cloth : clothes_vec)
            ans *= (cloth.second + 1);

        cout << ans-1 << '\n'; 
    }
}