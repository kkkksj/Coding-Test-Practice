#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

double a, b, v;

int main(void)
{
    cin >> a;
    cin >> b;
    cin >> v;

    cout << fixed;
    cout.precision(0);
    cout << ceil((v-a)/(a-b)) + 1 << endl;
}