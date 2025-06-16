#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Sort(vector<string> a, vector<string> b){
    if(a[3] != b[3])
        return stoi(a[3]) < stoi(b[3]);
    else if(a[2] != b[2])
        return stoi(a[2]) < stoi(b[2]);
    else 
        return stoi(a[1]) < stoi(b[1]);
}

int main() { 
    int n;
    cin >> n;

    vector<vector<string>> list (n, vector<string> (4));
    for(int i=0; i<n; i++)
        cin >> list[i][0] >> list[i][1] >> list[i][2] >> list[i][3];
    
    sort(list.begin(), list.end(), Sort);

    cout << list[n-1][0] << '\n';
    cout << list[0][0] << '\n';
}