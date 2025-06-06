#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt=1;
    int up=1;
    int down=1;
    int turn=1;
    while(cnt<n){
        if(turn % 2 == 1){
            if(down==turn){
                down++;
                turn++;
            }
            else{
                down++;
                up--;
            }
        }
        else{
            if(up==turn){
                up++;
                turn++;
            }
            else{
                up++;
                down--;
            }
        }
        cnt++;
    }
    cout << up << '/' << down;
}