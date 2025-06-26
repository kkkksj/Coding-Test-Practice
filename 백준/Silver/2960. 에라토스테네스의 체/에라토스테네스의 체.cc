#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool IsPrime(int num){
    for(int i=2; i<sqrt(num); i++){
        if(num/2 == 0)
            return 0;
    }
    return 1;
}

bool Erase(vector<int> &list, int num, int k, int n, int &cnt){
    for(int i=num; i<n+1; i+=num){
        if(list[i] !=0){
            cnt++;
            if(cnt == k){
                cout << list[i] << '\n';
                return 1;
            }
            list[i] = 0;
        }
    }
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> list (n+1);
    for(int i=2; i<n+1; i++)
        list[i] = i;
    
    int cnt = 0;
    for(int i=2; i<n+1; i++){
        if(list[i] != 0){
            if(IsPrime(list[i]))
                if(Erase(list, i, k, n, cnt))
                    break;
        }
    }
}