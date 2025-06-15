#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() { 
    string board;
    cin >> board;

    size_t point_4, point_2;
    while(1){
        point_4 = board.find("XXXX");
        point_2 = board.find("XX");
        if(point_4 != string::npos)
            board.replace(point_4, 4, "AAAA");
        else if(point_2 != string::npos)
            board.replace(point_2, 2, "BB");
        else
            break;
    }
    if(board.find("X") != string::npos)
        cout << -1 << '\n';
    else
        cout << board << '\n';    
}