#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std; 

int num;
int new_num;
int cnt = 0;

int main(void)
{
    cin >> num;

    int now_num = num;
    while(1){
        cnt += 1;
        int sum_each = now_num / 10 + now_num % 10;
        new_num = (now_num % 10)*10 + (sum_each % 10);

        if (new_num == num)
            break;
        now_num = new_num;
    }
    cout << cnt << endl;
}