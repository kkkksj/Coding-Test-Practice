#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int sz = 10001;

int main() {
    int arr[sz] = {0,};
    for(int i=1; i<sz; i++){
        int num = i;
        if(arr[num] == 0){
            while(num < sz){
                int sum=0;
                for(char c:to_string(num)){
                    sum += int(c-'0');
                }
                sum = sum + num;
                if(sum > 10000)
                    break;
                arr[sum] = 1;
                num = sum;
            }
        }
    }

    for(int i=1; i<sz; i++)
        if(arr[i] == 0)
            cout << i << '\n';
}