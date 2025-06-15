#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

bool Sort_Medal(vector<int> a, vector<int> b){
    if(a[1] != b[1])
        return a[1] > b[1];
    else if(a[2] != b[2])
        return a[2] > b[2];
    else if(a[3] != b[3])
        return a[3] > b[3];
    else    
        return a[0] < b[0];
}

int main() { 
    int n, k;
    cin >> n >> k;

    vector<vector<int>> medal (n, vector<int> (4));
    for(int i=0; i<n; i++)
        cin >> medal[i][0] >> medal[i][1] >> medal[i][2] >> medal[i][3];
    sort(medal.begin(), medal.end(), Sort_Medal);

    int rank=1;
    int gap=1;
    for(int i=0; i<n; i++){
        if(i>0){
            if(medal[i][1] == medal[i-1][1] and medal[i][2] == medal[i-1][2] and medal[i][3] == medal[i-1][3])
                gap++;
            else{
                rank += gap;
                gap = 1;
            }
        }
        if(medal[i][0] == k)
            break;
    }
    cout << rank << '\n';
}