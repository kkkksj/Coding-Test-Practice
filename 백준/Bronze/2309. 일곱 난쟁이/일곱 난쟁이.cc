#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std; 

vector<int> height;
int cm;
int sum = 0;

int main() {
    for(int i=0; i<9; i++){
        cin >> cm;
        sum += cm;
        height.push_back(cm);
    }

    sort(height.begin(), height.end());
    int rest = sum - 100;
    int not_dwarf1, not_dwarf2;
    for(int j=0; j<9; j++){
        for(int k=j+1; k<9; k++)
            if(height[j] + height[k] == rest){
                not_dwarf1 = height[j];
                not_dwarf2 = height[k];
            }
    }
    
    for(int cm : height)
        if(cm != not_dwarf1 && cm != not_dwarf2)
            cout << cm << '\n';
}