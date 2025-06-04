#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std; 

int score = 0;

int main() {
    int s;
    for(int i=0; i<10; i++){
        cin >> s;
        if((score + s) >= 100){
            if(100-score < (score+s)-100)
                break;
            else{
                score = score + s;
                break;
            }
            break;
        }
        score = score + s;
    }
    cout << score << '\n';
}