#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

int cal(int num, int p){
    int ret = 0;
    while(num > 0){
        ret += pow((num%10), p);
        num /= 10;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, p;
    cin >> a >> p;

    unordered_map<int, int> arr;
    int i = 0;
    while(1){
        auto idx = arr.find(a);
        if(idx != arr.end()){
            cout << arr[a] << '\n';
            break;
        }
        arr[a] = i++;
        a = cal(a, p);
    }
}