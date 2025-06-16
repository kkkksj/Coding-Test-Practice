#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() { 
    int n;
    cin >> n;

    cin.ignore();
    vector<string> room (n);
    for(int i=0; i<n; i++)
        getline(cin, room[i]);

    int cnt_sero;
    int cnt_garo;
    int ans_sero = 0;
    int ans_garo = 0;
    for(int i=0; i<n; i++){
        cnt_sero = 0;
        cnt_garo = 0;
        for(int j=0; j<n; j++){
            if(room[i][j] == 'X')
                cnt_garo = 0;
            else    
                cnt_garo++;
            if(room[j][i] == 'X')
                cnt_sero = 0;
            else
                cnt_sero++;
            
            if(cnt_garo == 2)
                ans_garo++;
            if(cnt_sero == 2)
                ans_sero++;
        }
    }
    cout << ans_garo << ' ' << ans_sero << '\n';
}