#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std; 

vector<int> ans;
int num;

int main() {
    cin >> num;
    int n = 2;
    while(num > 1){
        if(num % n == 0){
            num = num / n;
            ans.push_back(n);
        }
        else    
            n++;
    }

    for(int answer : ans)
        cout << answer << '\n';
}