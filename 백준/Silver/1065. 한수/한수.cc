#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

bool IsHannum(string number){
    int gap;
    for(size_t i=1; i<number.size(); i++){
        if(i==1)
            gap = int(number[i])-int(number[i-1]);
        else
            if(int(number[i])-int(number[i-1]) != gap)
                return 0;
    }
    return 1;
}

int main() { 
    int num;
    cin >> num;

    int ans = 0;
    for(int n=1; n<=num; n++){
        if(IsHannum(to_string(n)))
            ans++;
    }
    
    cout << ans << '\n';
}