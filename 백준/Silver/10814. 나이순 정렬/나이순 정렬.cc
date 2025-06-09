#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Sort_People(vector<string> a, vector<string> b){
    if(a[0] != b[0])
        return stoi(a[0]) < stoi(b[0]);
    else    
        return stoi(a[2]) < stoi(b[2]);
}

int main(){
    int n;
    cin >> n;

    vector<vector<string>> list(n, vector<string> (3, ""));
    for(int i=0; i<n; i++){
        cin >> list[i][0] >> list[i][1];
        list[i][2] = to_string(i);
    } 
    sort(list.begin(), list.end(), Sort_People);

    for(int i=0; i<n; i++)
        cout << list[i][0] << ' ' << list[i][1] << '\n';
}