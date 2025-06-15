#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() { 
    vector<vector<int>> score_list (8, vector<int> (2));
    for(int n=0; n<8; n++){
        cin >> score_list[n][0];
        score_list[n][1] = (n+1);
    }

    sort(score_list.begin(), score_list.end());
    int sum=0;
    for(int i=3; i<8; i++){
        sum += score_list[i][0];
    }
    cout << sum << '\n';
    for(int n=1; n<9; n++){
        if(n != score_list[0][1] && n != score_list[1][1] && n != score_list[2][1])
            cout << n << ' ';
    }
}