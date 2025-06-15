#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() { 
    int n;
    cin >> n;

    if(n%2 == 0)
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';
}