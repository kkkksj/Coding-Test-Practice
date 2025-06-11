#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n; 
    cin >> n;

    if(n%2 == 0)
        cout << "CY" << '\n';
    else
        cout << "SK" << '\n';   
}