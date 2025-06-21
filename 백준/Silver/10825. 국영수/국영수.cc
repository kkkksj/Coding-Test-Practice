#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Sort(vector<string> a, vector<string> b){
    if(a[1] != b[1])
        return stoi(a[1]) > stoi(b[1]);
    else if(a[2] != b[2])
        return stoi(a[2]) < stoi(b[2]);
    else if(a[3] != b[3])
        return stoi(a[3]) > stoi(b[3]);
    else
        return a[0] < b[0];
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> score (n, vector<string> (4));
    for(int i=0; i<n; i++)
        cin >> score[i][0] >> score[i][1] >> score[i][2] >> score[i][3];
    
    sort(score.begin(), score.end(), Sort);

    for(int i=0; i<n; i++)
        cout << score[i][0] << '\n';
}