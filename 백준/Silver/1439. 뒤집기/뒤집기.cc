#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() { 
    string zeroone;
    cin >> zeroone;

    zeroone += "2";
    char before_c = zeroone[0];
    int arr[2] = {0,};
    arr[int(before_c - '0')]++;
    for(char now_c : zeroone){
        if(now_c != before_c){
            arr[int(before_c - '0')]++;
            before_c = now_c;
        }
    }

    cout << min(arr[0], arr[1]) << '\n';
}