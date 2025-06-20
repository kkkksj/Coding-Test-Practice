#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> name_num;
    vector<string> num_name (n+1);
    string name;
    for(int i=0; i<n; i++){
        cin >> name;
        name_num[name] = i+1;
        num_name[i+1] = name;
    }

    string quiz;
    for(int i=0; i<m; i++){
        cin >> quiz;
        if(quiz[0] >='1'&& quiz[0] <='9')
            cout << num_name[stoi(quiz)] << '\n';
        else
            cout << name_num[quiz] << '\n';
    }
}