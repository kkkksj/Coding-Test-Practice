#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cin >> input;

    string alpha[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string replace_alpha = "0";

    size_t idx;
    for(int i=0; i<8; i++){
        idx = input.find(alpha[i]);
        while(idx != string::npos){
            input.replace(idx, alpha[i].length(), replace_alpha);
            idx = input.find(alpha[i]);
        }
    }
    cout << input.length() << endl;
}