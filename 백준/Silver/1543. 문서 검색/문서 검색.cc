#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() { 
    string text, find;
    getline(cin, text);
    getline(cin, find);

    size_t point;
    int cnt = 0;
    while(1){
        point = text.find(find);
        if(point == string::npos)
            break;
        text = text.replace(point, find.size(), "0");
        cnt++;
    }
    cout << count(text.begin(), text.end(), '0') << '\n';
}